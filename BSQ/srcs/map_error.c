/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:09:22 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 21:09:45 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	map_error(t_map *map_arr, int i)
{	
	if (map_arr[i].error != 1)
		write(1, "map error\n", 10);
	map_arr[i].error = 1;
}
