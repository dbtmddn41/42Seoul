/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoi <bchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:56:28 by bchoi             #+#    #+#             */
/*   Updated: 2021/09/26 23:23:13 by bchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

char	*write_dict(int *i, char *buf, char **num, char *to_print)
{
	int	check;

	while (is_space(buf[*i]) || buf[*i] == ':')
		(*i)++;
	while (buf[*i] != '\n')
	{
		check = 0;
		while (!is_space(buf[*i]) && buf[*i] != '\n')
			*to_print++ = buf[(*i)++];
		while (is_space(buf[*i]))
		{
			(*i)++;
			check = 1;
		}
		if (check == 1 && buf[*i] != '\n')
			*to_print++ = ' ';
		if (buf[*i] == '\n')
			break ;
	}
	while (**num != '/')
		(*num)++;
	if (*(++(*num)) != '\0')
		*to_print++ = ' ';
	return (to_print);
}

int	is_same(char *number, char *num)
{
	int	i;

	i = 0;
	while (number[i] != '\0' || *num != '/')
	{
		if (number[i] != *num)
			return (0);
		i++;
		num++;
	}
	return (1);
}

int	open_dict(int n, char *buf, char *num, char *to_print)
{
	int		i;
	int		j;
	char	number[30];

	i = 0;
	while (i < n)
	{
		j = 0;
		while (buf[i] != ':' && buf[i] != ' ')
			number[j++] = buf[i++];
		number[j++] = '\0';
		i++;
		if (is_same(number, num) == 1)
		{
			to_print = write_dict(&i, buf, &num, to_print);
			if (*num == 0)
				return (1);
			i = 0;
			continue ;
		}
		while (buf[i] != '\n' && i + 1 < n)
			i++;
		i++;
	}
	return (-1);
}
