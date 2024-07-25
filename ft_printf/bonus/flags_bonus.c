/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:57:00 by slyu              #+#    #+#             */
/*   Updated: 2022/02/16 22:57:03 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	flag_set(int *i, t_partial *part, const char *fstr, int wid_pre)
{
	int		j;
	char	*num;
	int		n;

	if (wid_pre == 1)
		(*i)++;
	j = 0;
	while (ft_isdigit(fstr[*i + j]))
		j++;
	num = malloc(j + 1);
	if (!num)
		return (-1);
	ft_memcpy(num, fstr + *i, j);
	num[j] = '\0';
	n = ft_atoi(num);
	free(num);
	if (n < 0)
		return (-1);
	else
		part->width[wid_pre] = n;
	*i += j - 1;
	return (1);
}

int	istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u'
		|| c == 'i' || c == 'x' || c == 'X' || c == 's' || c == '%')
		return (1);
	return (0);
}

int	check_flag(int *i, t_partial *part, const char *fstr)
{
	enum e_flag;
	if (fstr[*i] == '-')
		part->flag[minus] = 1;
	else if (fstr[*i] == '0')
		part->flag[zero] = 1;
	else if (fstr[*i] == '.')
		flag_set(i, part, fstr, 1);
	else if (fstr[*i] == '#')
		part->flag[sharp] = 1;
	else if (fstr[*i] == ' ')
		part->flag[space] = 1;
	else if (fstr[*i] == '+')
		part->flag[plus] = 1;
	else if (ft_isdigit(fstr[*i]))
		flag_set(i, part, fstr, 0);
	else
		return (0);
	return (1);
}

void	fill_precision(int precision, char **num_str, int s_len)
{
	char	*new_str;

	new_str = malloc(precision + 1);
	ft_memset(new_str, '0', precision);
	new_str[precision] = '\0';
	ft_memcpy(new_str + precision - s_len, *num_str, s_len);
	free(*num_str);
	*num_str = new_str;
}

char	*str_arg(char *s)
{
	if (s)
		return (ft_strdup(s));
	else
		return (ft_strdup("(null)"));
}
