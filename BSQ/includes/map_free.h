/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:21:07 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 21:59:39 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FREE_H
# define MAP_FREE_H
# include "find_square.h"

void	map_inside_free(t_map *map_arr, int argc);
void	map_free(t_map *map_arr);
#endif