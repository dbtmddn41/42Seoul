/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:07:22 by slyu              #+#    #+#             */
/*   Updated: 2022/01/05 20:07:24 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

static void	init(int *index, int *buho, const char *s)
{
	*index = 0;
	while (is_space(s[*index]))
		(*index)++;
	*buho = 1;
	if (s[*index] == '+')
		(*index)++;
	else if (s[*index] == '-')
	{
		*buho = -1;
		(*index)++;
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		buho;
	long	integer;

	init(&i, &buho, str);
	integer = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		integer *= 10;
		integer += str[i] - '0';
		if (integer < 0)
		{
			if (buho == -1)
				return (0);
			else if (buho == 1)
				return (-1);
		}
		i++;
	}
	return (buho * (int)integer);
}
