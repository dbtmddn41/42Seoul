/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:23:06 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 22:52:02 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct t_map
{
	char		**map;
	int			**int_map;
	int			info_len;
	int			file_len;
	int			column_size;
	long long	row_size;
	char		road;
	char		obs;
	char		square;
	int			error;
}	t_map;
void	init_map(t_map *map_arr, int argc);
#endif