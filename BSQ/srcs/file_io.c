/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:21:16 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 22:25:49 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

t_map	*open_argv(int argc, char **argv)
{
	t_map	*map_arr;
	int		i;

	if (argc == 1)
	{
		map_arr = (t_map *)malloc(sizeof(t_map));
		if (!map_arr)
			malloc_error();
		init_map(map_arr, argc);
		open_stdin_file(map_arr);
	}
	else
	{
		map_arr = (t_map *)malloc(sizeof(t_map) * (argc - 1));
		if (!map_arr)
			malloc_error();
		init_map(map_arr, argc);
		i = 0;
		while (i < argc - 1)
		{
			open_file(argv, i++, map_arr);
		}
	}
	return (map_arr);
}

void	print_map(t_map *map_arr, int i)
{
	int	index;

	index = 0;
	if (map_arr[i].error != 1)
	{
		while (index < map_arr[i].row_size)
		{
			write(1, map_arr[i].map[index++], map_arr[i].column_size);
			write(1, "\n", 1);
		}
	}
}

void	open_file(char **argv, int i, t_map *map_arr)
{
	int		fd;
	int		file_len;
	int		info_len;
	char	*file_str_type;

	fd = open(argv[i + 1], O_RDONLY);
	if (fd < 0)
		file_open_error();
	file_len = find_file_size(fd);
	close(fd);
	fd = open(argv[i + 1], O_RDONLY);
	if (fd < 0)
		file_open_error();
	file_str_type = read_file(fd, file_len);
	info_len = read_info(file_str_type, map_arr, i);
	if (file_len <= info_len + 1)
	{
		map_error(map_arr, i);
		return ;
	}
	map_arr[i].info_len = info_len;
	map_arr[i].file_len = file_len;
	read_map(file_str_type + info_len, map_arr, i);
	free(file_str_type);
	close(fd);
}

void	open_stdin_file(t_map *map_arr)
{
	int		info_len;
	int		file_len;
	char	*file_str_type;
	char	buf[1];

	file_len = 0;
	file_str_type = read_stdin_file(&file_len, buf);
	info_len = read_info(file_str_type, map_arr, 0);
	if (file_len <= info_len + 1)
	{
		map_error(map_arr, 0);
		exit(1);
	}
	map_arr[0].info_len = info_len;
	map_arr[0].file_len = file_len;
	read_map(file_str_type + info_len, map_arr, 0);
	free(file_str_type);
}

void	int_map_print(int argc, t_map *map_arr)
{
	int		i;

	i = -1;
	if (argc == 1)
	{
		if (map_arr[0].error == 1)
			return ;
		make_int_map(map_arr);
		search_biggest(map_arr);
		print_map(map_arr, 0);
	}
	else
	{
		while (++i < argc - 1)
		{
			if (map_arr[i].error == 1)
				continue ;
			make_int_map(&map_arr[i]);
			search_biggest(&map_arr[i]);
			if (i != 0)
				write(1, "\n", 1);
			print_map(map_arr, i);
		}
	}
}
