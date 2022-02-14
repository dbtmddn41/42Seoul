/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:25:53 by slyu              #+#    #+#             */
/*   Updated: 2022/02/12 21:25:55 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_u(va_list ap, t_partial *part)
{
	unsigned int	num;
	char			*num_str;
	int				s_len;
	char			*c_str;
	int				i;

	num = va_arg(ap, unsigned int);
	num_str = ft_itoa_unsigned(num);
	if (!num_str)
		return (-1);
	s_len = precision(part, &num_str, num);
	if (part->width[0] < s_len)
		part->width[0] = s_len;
	c_str = set_cstr(part->width[0], part->flag[zero]);
	if (!c_str)
	{
		free(num_str);
		return (-1);
	}
	i = print_cstr(c_str, num_str, s_len, part);
	free_all(2, num_str, c_str);
	return (i);
}

int	print_x(va_list ap, t_partial *part, int islarge)
{
	char	*s;
	int		i;

	s = x_str(ap, part);
	if (!s)
		return (-1);
	if (islarge)
		capitalize(s);
	i = ft_putstr(s);
	free(s);
	return (i);
}

char	*x_str(va_list ap, t_partial *part)
{
	unsigned int	n;
	char			*num_str;
	int				s_len;
	char			*c_str;

	n = va_arg(ap, unsigned int);
	num_str = ft_itoa_x(n);
	if (!num_str)
		return (0);
	s_len = precision(part, &num_str, n);
	adjust_width_x(part, s_len, n);
	c_str = set_cstr(part->width[0], part->flag[zero]);
	if (!c_str)
	{
		free(num_str);
		return (0);
	}
	if (n == 0)
		part->flag[sharp] = 0;
	cstr_xp(part, c_str, num_str, s_len);
	free(num_str);
	return (c_str);
}

int	print_percent(t_partial *part)
{
	char	*c_str;
	int		i;

	if (part->width[0] < 1)
		part->width[0] = 1;
	c_str = set_cstr(part->width[0], part->flag[zero]);
	if (!c_str)
		return (-1);
	if (part->flag[minus])
		c_str[0] = '%';
	else
		c_str[part->width[0] - 1] = '%';
	i = ft_putstr(c_str);
	free(c_str);
	return (i);
}

int	print_c(va_list ap, t_partial *part)
{
	char	c;
	int		i;
	char	*c_str;

	c = va_arg(ap, int);
	if (part->width[0] < 1)
		part->width[0] = 1;
	c_str = set_cstr(part->width[0], part->flag[zero]);
	if (!c_str)
		return (-1);
	if (part->flag[minus])
		c_str[0] = c;
	else
		c_str[part->width[0] - 1] = c;
	i = ft_putmem(c_str, part->width[0]);
	free(c_str);
	return (i);
}
