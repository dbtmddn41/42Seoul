/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:05:11 by slyu              #+#    #+#             */
/*   Updated: 2022/01/27 18:05:16 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	t_list		*buf;
	char		*line;
	int			fd_check;

	fd_check = 1;
	if (!save[fd])
	{
		save[fd] = malloc(BUFFER_SIZE);
		if (!save[fd])
			return (0);
		ft_memset(save[fd], 0, BUFFER_SIZE);
		fd_check = 0;
	}
	if (ft_strnchr(save[fd], '\n', BUFFER_SIZE) != -1 && fd_check)
		line = next_line_in_save(fd, save);
	else
	{
		buf = malloc(sizeof(t_list));
		if (!buf)
			return (0);
		line = read_next_line(fd, save, &buf);
	}
	return (line);
}

char	*next_line_in_save(int fd, char **save)
{
	int		size;
	char	*line;

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	size = ft_strnchr(save[fd], '\n', BUFFER_SIZE);
	line = malloc(size + 1);
	if (!line)
		return (0);
	ft_strlcpy(line, save[fd], size + 1);
	line[size] = '\0';
	ft_memmove(save[fd], save[fd] + size + 1, BUFFER_SIZE - size - 1);
	ft_memset(save[fd] + BUFFER_SIZE - size - 1, 0, size + 1);
	return (line);
}

char	*read_next_line(int fd, char **save, t_list **buf)
{
	int		lst_size;
	int		last_num;
	int		flag;
	char	*line;

	flag = fd2list(fd, buf, &lst_size, &last_num);
	if ((flag == -1 || (lst_size == 1 && last_num == 0)) && save[fd][0] == 0)
	{
		free(save[fd]);
		save[fd] = 0;
		return (0);
	}
	line = malloc((lst_size - 1) * BUFFER_SIZE + last_num);
	if (!line)
		return (0);
	flag = ft_strlcpy(line, save[fd], BUFFER_SIZE);
	list2line(line + flag, buf, last_num);
	ft_memmove(save[fd], (*buf)->content + last_num + 1,
		BUFFER_SIZE - last_num - 1);
	free(*buf);
	return (line);
}

int	fd2list(int fd, t_list **buf, int *lst_size, int *last_num)
{
	int		read_num;
	t_list	*curr;

	*lst_size = 0;
	curr = *buf;
	while (++(*lst_size) && curr != 0)
	{
		ft_memset(curr->content, 0, BUFFER_SIZE);
		read_num = read(fd, curr->content, BUFFER_SIZE);
		if (read_num == -1)
			break ;
		*last_num = ft_strnchr(curr->content, '\n', BUFFER_SIZE);
		if (read_num < BUFFER_SIZE || *last_num != -1)
		{
			curr->next = NULL;
			if (read_num < BUFFER_SIZE && *last_num == -1)
				*last_num = read_num;
			return (1);
		}
		curr->next = malloc(sizeof(t_list));
		curr = curr->next;
	}
	ft_lstclear(buf);
	return (-1);
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
	ft_memmove(line, (*buf)->content, last_num);
	line[last_num] = '\0';
}
