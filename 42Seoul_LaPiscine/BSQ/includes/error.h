/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:17:57 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 20:14:13 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "find_square.h"

void	info_error(void);
void	file_open_error(void);
void	file_read_error(void);
void	malloc_error(void);
void	overflow_error(void);
void	map_error(t_map *map_arr, int i);
#endif