/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoi <bchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 22:39:15 by bchoi             #+#    #+#             */
/*   Updated: 2021/09/26 23:29:53 by bchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int				check_error(char *num_arr, unsigned int num);
void			ft_putstr(char *str);
int				check_argc(int argc, char **argv, char **nb, char **dictpath);
void			start_search(char *num_arr, char *path);
unsigned int	ft_atoi(char *str);
int				check_zero(char *str);
int				check_jarisu(unsigned int num);
void			process(char *num_arr, int *index, unsigned int num, int i);
void			process_jarisu(char *num_arr, int *index, int i);
void			process_2(char *num_arr, int *index, unsigned int num, int j);
char			*make_arr(unsigned int num);
int				is_space(char c);
char			*write_dict(int *i, char *buf, char **num, char *to_print);
int				is_same(char *number, char *num);
int				open_dict(int n, char *buf, char *num, char *to_print);
#endif
