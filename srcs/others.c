/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:43:49 by slyu              #+#    #+#             */
/*   Updated: 2022/02/11 18:44:05 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adjust_width_d(t_partial *part, int s_len, int num)
{
	if (part->width[0] < s_len + 1)
	{
		if (part->flag[space] || num < 0 || part->flag[plus])
			part->width[0] = s_len + 1;
		else
			part->width[0] = s_len;
	}
}

void	adjust_width_x(t_partial *part, int s_len, unsigned int num)
{
	int	sh;

	if (part->flag[sharp] && num != 0)
		sh = 2;
	else
		sh = 0;
	if (part->width[0] < s_len + sh)
		part->width[0] = s_len + sh;
}

void	free_all(int n, ...)
{
	va_list	ap;
	void	*p;

	va_start(ap, n);
	while (n > 0)
	{
		p = va_arg(ap, void *);
		free(p);
		n--;
	}
	va_end(ap);
}

int	ft_putmem(char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

int	precision(t_partial *part, char **s, unsigned long n)
{
	int	s_len;

	s_len = ft_strlen(*s);
	if (part->width[1] > s_len)
		fill_precision(part->width[1], s, s_len);
	else if (part->width[1] == 0 && n == 0)
		(*s)[0] = '\0';
	return (ft_strlen(*s));
}
