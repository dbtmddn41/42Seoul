/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:12:40 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 21:51:38 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_INT_MAP_H
# define MAKE_INT_MAP_H
# include "map.h"

void	plus_one(int x, int y, t_map *box);
void	make_int_map(t_map *box);
int		check_possible(int x, int y, int size, int **int_map);
void	search_biggest(t_map *box);
void	draw_in_map(int	*map, t_map *box);
#endif