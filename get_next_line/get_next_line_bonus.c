/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 06:41:46 by slyu              #+#    #+#             */
/*   Updated: 2022/01/31 06:41:48 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	t_list		*buf;
	char		*line;
	int			fd_check;

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	fd_check = 1;
	if (!save[fd])
	{
		save[fd] = malloc(BUFFER_SIZE);
		if (!save[fd])
			return (0);
		ft_memset(save[fd], 0, BUFFER_SIZE);
		fd_check = 0;
	}
	if (fd_check && ft_strnchr(save[fd], '\n', BUFFER_SIZE) != -1)
		line = next_line_in_save(fd, save);
	else
	{
		buf = malloc(sizeof(t_list));
		line = read_next_line(fd, save, &buf);
	}
	return (line);
}

char	*next_line_in_save(int fd, char **save)
{
	int		size;
	char	*line;

	size = ft_strnchr(save[fd], '\n', BUFFER_SIZE) + 1;
	line = malloc(size + 1);
	if (!line)
		return (0);
	ft_strlcpy(line, save[fd], size + 1);
	line[size] = '\0';
	ft_memmove(save[fd], save[fd] + size, BUFFER_SIZE - size);
	ft_memset(save[fd] + BUFFER_SIZE - size, 0, size);
	return (line);
}

char	*read_next_line(int fd, char **save, t_list **buf)
{
	int		lst_size;
	int		last;
	int		flag;
	char	*line;

	if (!buf)
		return (0);
	flag = fd2list(fd, *buf, &lst_size, &last);
	if ((flag == -1 || (flag == 0 && lst_size == 1 && last == 0))
		&& save[fd][0] == 0)
	{
		ft_lstclear(buf);
		free(save[fd]);
		save[fd] = 0;
		return (0);
	}
	line = malloc(lst_size * BUFFER_SIZE + last + 1);
	if (!line)
		return (0);
	flag = ft_strlcpy(line, save[fd], BUFFER_SIZE);
	list2line(line + flag, buf, last);
	ft_memmove(save[fd], (*buf)->content + last + 1, BUFFER_SIZE - last - 1);
	ft_memset(save[fd] + BUFFER_SIZE - last - 1, 0, last + 1);
	free(*buf);
	return (line);
}

int	fd2list(int fd, t_list *buf, int *lst_size, int *last_num)
{
	int		read_num;

	*lst_size = 0;
	while (++(*lst_size) && buf != 0)
	{
		ft_memset(buf->content, 0, BUFFER_SIZE);
		read_num = read(fd, buf->content, BUFFER_SIZE);
		if (read_num == -1)
		{
			buf->next = NULL;
			return (-1);
		}
		*last_num = ft_strnchr(buf->content, '\n', BUFFER_SIZE);
		if (read_num < BUFFER_SIZE || *last_num != -1)
			break ;
		buf->next = malloc(sizeof(t_list));
		buf = buf->next;
	}
	buf->next = NULL;
	if (read_num < BUFFER_SIZE && *last_num == -1)
	{
		*last_num = read_num;
		return (0);
	}
	return (1);
}

void	list2line(char *line, t_list **buf, int last_num)
{
	t_list	*temp;

	while ((*buf)->next != NULL)
	{
		ft_memmove(line, (*buf)->content, BUFFER_SIZE);
		temp = (*buf)->next;
		free(*buf);
		*buf = temp;
		line += BUFFER_SIZE;
	}
	ft_memmove(line, (*buf)->content, last_num + 1);
	line[last_num + 1] = '\0';
}
