/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_able.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:37:49 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 22:58:18 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int	is_printable(char ch)
{
	if (32 < ch && 126 > ch)
		return (1);
	return (0);
}

int	is_map(t_map *map_arr, int i)
{
	char	obs;
	char	road;
	char	square;
	int		map_len;

	obs = map_arr[i].obs;
	road = map_arr[i].road;
	square = map_arr[i].square;
	map_len = map_arr[i].file_len - map_arr[i].info_len - 1;
	if (obs == road || road == square || square == obs)
	{
		map_error(map_arr, i);
		return (0);
	}
	if (!is_printable(obs) || !is_printable(road) || !is_printable(square))
	{
		map_error(map_arr, i);
		return (0);
	}
	if (map_arr[i].row_size != map_len / (map_arr[i].column_size + 1))
	{
		map_error(map_arr, i);
		return (0);
	}
	return (1);
}
