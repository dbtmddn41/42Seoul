/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:33:29 by slyu              #+#    #+#             */
/*   Updated: 2022/08/11 18:33:31 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**calc_pattern(int n)
{
	int	**dir;
	int	steps;
	int	res;

	steps = log_int(3, n / 3) + 1;
	dir = (int **)malloc(sizeof(int *) * (steps + 1));
	if (!dir)
		return (0);
	dir[0] = malloc(1);
	dir[0][0] = n;
	res = pattern_process(dir, steps);
	if (res == -1)
	{
		delete_all(dir);
		return(0);
	}
	return (dir);
}

int	pattern_process(int **dir, int steps)
{
	int	i;
	int	j;
	int	tri_num;

	i = 1;
	while (i <= steps)
	{
		tri_num = ft_pow(3, i);
		dir[i] = malloc(sizeof(int) * tri_num);
		if (!dir[i])
			return (-1);
		j = 0;
		while (j < tri_num / 3)
		{
			dir[i][j] = dir[i - 1][j] / 3;
			dir[i][j + tri_num / 3 * 2] = dir[i - 1][j] / 3;
			j++;
		}
		while (j < tri_num / 9 * 4)
		{
			dir[i][j] = dir[i - 1][tri_num / 3 * 2 - 1 - j] / 3;
			dir[i][j] += dir[i - 1][tri_num / 3 * 2 - 1 - j] % 3;
			j++;
		}
		while (j < tri_num / 3 * 2)
		{
			dir[i][j] = (-1) * (dir[i - 1][tri_num / 3 * 2 - 1 - j] / 3);
			dir[i][j] -= dir[i - 1][tri_num / 3 * 2 - 1 - j] % 3;
			j++;
		}
		i++;
	}
	return (0);
}