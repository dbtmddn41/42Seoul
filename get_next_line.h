/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:22:14 by slyu              #+#    #+#             */
/*   Updated: 2022/01/27 18:22:16 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	char			content[BUFFER_SIZE];
	struct s_list	*next;
}t_list;

int		ft_strnchr(const char *s, char c, int len);
void	*ft_memset(void *dest, int c, size_t count);
void	ft_lstclear(t_list **lst);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*get_next_line(int fd);
char	*next_line_in_save(int fd, char **save);
char	*read_next_line(int fd, char **save, t_list **buf);
int		fd2list(int fd, t_list **buf, int *lst_size, int *last_num);
void	list2line(char *line, t_list **buf, int last_num);
int		ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
