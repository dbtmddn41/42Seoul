/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:49:53 by slyu              #+#    #+#             */
/*   Updated: 2022/02/06 04:49:56 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_fstr(va_list ap, t_partial *part)
{
	int		printed;
	int		res;

	printed = 0;
	while (part != NULL)
	{
		if (part->isformat)
		{
			res = print_format(ap, part);
			if (res == -1)
				return (-1);
			printed += res;
		}
		else
			printed += ft_putstr(part->str);
		part = part->next;
	}
	return (printed);
}

int	print_format(va_list ap, t_partial *part)
{
	int	res;

	if (part->type == 'c')
		res = print_c(ap, part);
	else if (part->type == 's')
		res = print_s(ap, part);
	else if (part->type == 'p')
		res = print_p(ap, part);
	else if (part->type == 'd' || part->type == 'i')
		res = print_d(ap, part);
	else if (part->type == 'u')
		res = print_u(ap, part);
	else if (part->type == 'x')
		res = print_x(ap, part, 0);
	else if (part->type == 'X')
		res = print_x(ap, part, 1);
	else if (part->type == '%')
		res = print_percent(part);
	else
		res = -1;
	return (res);
}

int	print_s(va_list ap, t_partial *part)
{
	int		i;
	char	*s;
	char	*c_str;
	int		s_len;

	s = str_arg(va_arg(ap, char *));
	if (!s)
		return (-1);
	s_len = ft_strlen(s);
	if (s_len < 0)
		return (-1);
	if (part-> width[1] != -1 && part->width[1] < s_len)
		s[part->width[1]] = '\0';
	s_len = ft_strlen(s);
	if (part->width[0] < s_len)
		part->width[0] = s_len;
	c_str = set_cstr(part->width[0], part->flag[zero]);
	if (!c_str)
	{
		free(s);
		return (-1);
	}
	i = print_cstr(c_str, s, s_len, part);
	free_all(2, c_str, s);
	return (i);
}

int	print_p(va_list ap, t_partial *part)
{
	unsigned long	addr;
	char			*addr_str;
	char			*c_str;
	int				s_len;
	int				i;

	addr = (unsigned long)va_arg(ap, void *);
	addr_str = ft_itoa_p(addr);
	if (!addr_str)
		return (-1);
	s_len = precision(part, &addr_str, addr);
	if (part->width[0] < s_len + 2)
		part->width[0] = s_len + 2;
	c_str = set_cstr(part->width[0], part->flag[zero]);
	if (!c_str)
	{
		free(addr_str);
		return (0);
	}
	part->flag[sharp] = 1;
	cstr_xp(part, c_str, addr_str, s_len);
	i = ft_putstr(c_str);
	free_all(2, c_str, addr_str);
	return (i);
}

int	print_d(va_list ap, t_partial *part)
{
	int		num;
	char	*num_str;
	char	*c_str;
	int		s_len;
	int		i;

	num = va_arg(ap, int);
	num_str = ft_itoa_nosign(num);
	if (!num_str)
		return (-1);
	s_len = precision(part, &num_str, num);
	adjust_width_d(part, s_len, num);
	c_str = set_cstr(part->width[0], part->flag[zero]);
	if (!c_str)
	{
		free(num_str);
		return (-1);
	}
	i = print_cstr_d(part, c_str, num_str, num);
	free_all(2, c_str, num_str);
	return (i);
}
