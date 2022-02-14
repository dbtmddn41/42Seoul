/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:38:18 by slyu              #+#    #+#             */
/*   Updated: 2022/02/14 18:53:27 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*set_cstr(int width, char zero)
{
	char	*complete_str;

	complete_str = malloc(width + 1);
	if (!complete_str)
		return (0);
	if (zero)
		ft_memset(complete_str, '0', width);
	else
		ft_memset(complete_str, ' ', width);
	complete_str[width] = '\0';
	return (complete_str);
}

int	print_cstr(char *c_str, char *str, int s_len, t_partial *part)
{
	if (part->flag[minus])
		ft_memcpy(c_str, str, s_len);
	else
		ft_memcpy(c_str + part->width[0] - s_len, str, s_len);
	return (ft_putstr(c_str));
}

int	print_cstr_d(t_partial *part, char *c_str, char *num_str, int num)
{
	int		front_flag;
	char	sign;

	front_flag = 0;
	if (part->flag[plus] == 0 && num >= 0)
	{
		if (part->flag[space])
		{
			c_str[0] = ' ';
			front_flag = 1;
		}
		numstr2cstr(part, num_str, c_str, front_flag);
	}
	else
	{
		sign = '+';
		if (num < 0)
			sign = '-';
		numstr2cstr(part, num_str, c_str, 1);
		if (part->flag[zero] || part->flag[minus])
			c_str[0] = sign;
		else
			c_str[part->width[0] - ft_strlen(num_str) - 1] = sign;
	}
	return (ft_putstr(c_str));
}

void	cstr_xp(t_partial *part, char *c_str, char *num_str, int s_len)
{
	if (part->flag[sharp])
	{
		numstr2cstr(part, num_str, c_str, 2);
		if (part->flag[zero] || part->flag[minus])
		{
			*c_str = '0';
			*(c_str + 1) = 'x';
		}
		else
		{
			c_str[part->width[0] - s_len - 2] = '0';
			c_str[part->width[0] - s_len - 1] = 'x';
		}
	}
	else
		numstr2cstr(part, num_str, c_str, 0);
}

void	numstr2cstr(t_partial *part, char *num_str, char *c_str, int front)
{
	int	s_len;

	s_len = ft_strlen(num_str);
	if (part->flag[minus])
		ft_memcpy(c_str + front, num_str, s_len);
	else
		ft_memcpy(c_str + part->width[0] - s_len, num_str, s_len);
}
