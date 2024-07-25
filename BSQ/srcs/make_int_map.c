/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:01:27 by slyu              #+#    #+#             */
/*   Updated: 2021/09/30 00:01:35 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	initialize_int_map(t_map *box)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= box -> row_size)
	{
		x = 0;
		while (x <= box -> column_size)
		{
			box -> int_map[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	make_int_map(t_map *box)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	initialize_int_map(box);
	while (y <= box -> row_size)
	{
		x = 1;
		while (x <= box -> column_size)
		{
			if (box -> map[y - 1][x - 1] == box -> obs)
				plus_one(x, y, box);
			x++;
		}
		y++;
	}
}

void	plus_one(int x, int y, t_map *box)
{
	int	start_x;

	start_x = x;
	while (y <= box -> row_size)
	{
		x = start_x;
		while (x <= box -> column_size)
		{
			box -> int_map[y][x] += 1;
			x++;
		}
		y++;
	}
}
