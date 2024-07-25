/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:35:25 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 23:37:30 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	map_inside_free(t_map *map_arr, int argc)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		free(map_arr[0].map);
		free(map_arr[0].int_map);
	}
	else
	{
		while (i < argc - 1)
		{
			free(map_arr[i].map);
			free(map_arr[i++].int_map);
		}
	}
}

void	map_free(t_map *map_arr)
{
	free(map_arr);
}
