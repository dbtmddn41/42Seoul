/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoel.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:27:38 by slyu              #+#    #+#             */
/*   Updated: 2022/08/14 19:27:39 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**calc_pattern(int n, int steps)
{
	int	**dir;
	int	res;

	dir = (int **)malloc(sizeof(int *) * (steps + 1));
	if (!dir)
		return (0);
	dir[0] = malloc(1);
	dir[0][0] = n;
	res = pattern_process(dir, steps);
	if (res == -1)
	{
		delete_all(dir);
		return (0);
	}
	return (dir);
}

int	pattern_process(int **dir, int steps)
{
	int	i;
	int	tri_num;

	i = 1;
	while (i < steps)
	{
		tri_num = ft_pow(3, i);
		dir[i] = malloc(sizeof(int) * tri_num);
		if (!dir[i])
			return (-1);
		dp_pattern(dir, i, tri_num);
		i++;
	}
	return (0);
}

void	delete_all(int **to_del)
{
	int	i;

	i = 0;
	while (to_del[i] != 0)
	{
		free(to_del[i]);
		i++;
	}
	free(to_del);
}

void	dp_pattern(int **dir, int i, int tri_num)
{
	int	j;

	j = 0;
	while (j < tri_num / 3)
	{
		dir[i][j] = dir[i - 1][j] / 3;
		dir[i][j + tri_num / 3 * 2] = dir[i - 1][j] / 3;
		dir[i][j + tri_num / 3 * 2] += (dir[i - 1][j] % 3) / 2;
		j++;
	}
	while (j < tri_num / 9 * 4)
	{
		dir[i][j] = dir[i - 1][j - tri_num / 9] / 3;
		dir[i][j] += (dir[i - 1][j - tri_num / 9] % 3) * 3 / 2 % 2;
		j++;
	}
	while (j < tri_num / 3 * 2)
	{
		dir[i][j] = (-1) * (dir[i - 1][tri_num / 3 * 2 - 1 - j] / 3);
		dir[i][j] -= (dir[i - 1][tri_num / 3 * 2 - 1 - j] % 3) * 3 / 2 % 2;
		j++;
	}
}
