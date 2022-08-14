/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@stdent.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:37:04 by slyu              #+#    #+#             */
/*   Updated: 2022/08/11 17:37:06 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	log_int(int n, int x)
{
	long	m;
	int		cnt;

	m = 1;
	cnt = 0;
	while (1)
	{
		m *= n;
		if (m > __INT32_MAX__)
			return (-1);
		else if (x < m)
		return (cnt);
		cnt++;
	}
}

int	ft_pow(int n, int x)
{
	int		i;
	long	res;

	i = 0;
	res = 1;
	while (i < x)
	{
		res *= n;
		if (res > __INT32_MAX__)
			return (0);
		i++;
	}
	return ((int)res);
}

void	delete_all(int **to_del)
{
	while (*to_del != 0)
	{
		free(*to_del);
		(*to_del)++;
	}
	free(to_del);
}

void	ft_abs(int *a)
{
	if (*a < 0)
		*a *= -1;
}