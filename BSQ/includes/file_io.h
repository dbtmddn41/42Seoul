/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:22:31 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 22:43:25 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_IO_H
# define FILE_IO_H
# include "find_square.h"

t_map	*open_argv(int argc, char **argv);
void	open_file(char **argv, int i, t_map *map_arr);
int		find_file_size(int fd);
char	*read_file(int fd, int file_len);
int		read_info(char *str, t_map *map_arr, int i);
void	read_map(char *str, t_map *map_arr, int i);
char	*copy_map(char *str, t_map *map_arr, int i, int row);
int		line_len(char *str);
void	open_stdin_file(t_map *map_arr);
char	*read_stdin_file(int *file_len, char *buf);
void	print_map(t_map *map_arr, int i);
void	int_map_print(int argc, t_map *map_arr);
int		line_len(char *str);
void	expand_buf(char **stdin_file, int file_buf_size, int size);
void	ft_strcpy(char *dest, char *src, int buf_size, int size);
void	read_map_malloc(char *str, t_map *map_arr, int i, int c_size);
#endif