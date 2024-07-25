/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:19:58 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 21:09:41 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	info_error(void)
{
	write(1, "map error\n", 10);
	exit(1);
}

void	file_open_error(void)
{
	write(1, "file_open_error\n", 16);
	exit(1);
}

void	file_read_error(void)
{
	write(1, "file_read_error\n", 16);
	exit(1);
}

void	malloc_error(void)
{
	write(1, "malloc_error\n", 13);
	exit(1);
}

void	overflow_error(void)
{	
	write(1, "overflow_error\n", 15);
	exit(1);
}
