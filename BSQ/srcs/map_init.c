/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:23:18 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 21:28:52 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	init_map(t_map *map_arr, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		map_arr[i].map = NULL;
		map_arr[i].int_map = NULL;
		map_arr[i].info_len = -1;
		map_arr[i].file_len = -1;
		map_arr[i].column_size = -1;
		map_arr[i].row_size = -1;
		map_arr[i].road = '\0';
		map_arr[i].obs = '\0';
		map_arr[i].square = '\0';
		map_arr[i++].error = 0;
	}
}
