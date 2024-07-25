/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:39:37 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 23:38:00 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int	main(int argc, char **argv)
{
	t_map	*map_arr;

	map_arr = open_argv(argc, argv);
	int_map_print(argc, map_arr);
	map_inside_free(map_arr, argc);
	map_free(map_arr);
	return (0);
}
