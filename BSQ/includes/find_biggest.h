/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:04:43 by slyu              #+#    #+#             */
/*   Updated: 2021/09/30 00:04:44 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_BIGGEST_H
# define FIND_BIGGEST_H
# include "find_square.h"

int		check_possible(int x, int y, int size, int **int_map);
void	set_memory(int *memory, int *xys);
void	search_biggest(t_map *box);
void	draw_in_map(int	*memory, t_map *box);
#endif