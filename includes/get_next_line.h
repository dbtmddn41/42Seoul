/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:22:14 by slyu              #+#    #+#             */
/*   Updated: 2022/01/31 06:22:16 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_gnllist
{
	char			content[BUFFER_SIZE];
	struct s_gnllist	*next;
}t_gnllist;

int		gnl_strnchr(const char *s, char c, int len);
void	gnl_lstclear(t_gnllist **lst);
char	*get_next_line(int fd);
char	*next_line_in_save(int fd, char **save);
char	*read_next_line(int fd, char **save, t_gnllist **buf);
int		fd2list(int fd, t_gnllist *buf, int *lst_size, int *last_num);
void	list2line(char *line, t_gnllist **buf, int last_num);
int		gnl_strlcpy(char *dst, const char *src, size_t dstsize);

#endif