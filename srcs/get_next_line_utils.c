/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:33:44 by slyu              #+#    #+#             */
/*   Updated: 2022/01/27 18:33:50 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strnchr(const char *s, char c, int len)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	else
		return (-1);
}

void	gnl_lstclear(t_gnllist **lst)
{
	t_gnllist	*curr;
	t_gnllist	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*lst = NULL;
}

int	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i + 1 < dstsize && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	j = i;
	if (dstsize != 0)
		*(dst + i) = '\0';
	return (j);
}
