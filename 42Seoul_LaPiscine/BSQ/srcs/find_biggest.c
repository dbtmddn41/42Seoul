/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:05:02 by slyu              #+#    #+#             */
/*   Updated: 2021/09/30 10:29:01 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int	check_possible(int x, int y, int size, int **int_map)
{
	int	result;

	result = 0;
	result = int_map[y + size - 1][x + size - 1] - int_map[y + size - 1][x - 1];
	result -= int_map[y - 1][x + size - 1] - int_map[y - 1][x - 1];
	if (result == 0)
		return (1);
	else
		return (0);
}

void	set_memory(int *memory, int *xys)
{
	memory[4] = 1;
	memory[0] = xys[0] - 1;
	memory[1] = xys[1] - 1;
	memory[2] = xys[2];
	xys[2] += 1;
}

void	search_biggest(t_map *box)
{
	int	xys[3];
	int	memory[5];

	xys[1] = 0;
	xys[2] = 1;
	memory[4] = 0;
	while (++(xys[1]) + xys[2] - 1 <= box -> row_size)
	{
		xys[0] = 0;
		while (++xys[0] + xys[2] - 1 <= box -> column_size
			&& xys[1] + xys[2] - 1 <= box -> row_size)
		{
			while (check_possible(xys[0], xys[1], xys[2], box -> int_map))
			{
				set_memory(memory, xys);
				if (xys[1] + xys[2] - 1 > box -> row_size
					|| xys[0] + xys[2] - 1 > box -> column_size)
					break ;
			}
		}
	}
	if (memory[4])
		draw_in_map(memory, box);
}

void	draw_in_map(int	*memory, t_map *box)
{
	int	i;
	int	j;

	i = 0;
	while (i < memory[2])
	{
		j = 0;
		while (j < memory[2])
		{
			box -> map[memory[1] + i][memory[0] + j] = box -> square;
			j++;
		}
		i++;
	}
}
