/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:02:03 by slyu              #+#    #+#             */
/*   Updated: 2022/08/17 03:02:05 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(int *index, int *buho, const char *s)
{
	*index = 0;
	*buho = 1;
	if (s[*index] == '+')
		(*index)++;
	else if (s[*index] == '-')
	{
		*buho = -1;
		(*index)++;
	}
}

int	ft_atoi2(const char *str)
{
	int	i;
	int	buho;
	int	integer;

	init(&i, &buho, str);
	integer = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		integer *= 10;
		if (!ft_isdigit(str[i]))
			return (-1);
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
	return (buho * integer);
}
