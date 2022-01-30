/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 06:42:40 by slyu              #+#    #+#             */
/*   Updated: 2022/01/31 06:42:42 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	ft_strnchr(const char *s, char c, int len)
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

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		*((unsigned char *)(dest) + i) = (unsigned char)c;
		i++;
	}
	return (dest);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*curr;
	t_list	*temp;

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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (!dst && !src)
		return (dst);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*((char *)dst + len - 1 - i) = *((char *)src + len - 1 - i);
			i++;
		}
	}
	return (dst);
}

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
