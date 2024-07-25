/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:23:35 by slyu              #+#    #+#             */
/*   Updated: 2021/09/30 04:18:49 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(dest + i) != '\0')
		i++;
	while (*src != '\0')
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		strslen;
	int		i;
	int		seplen;

	if (size <= 0)
		return (malloc(0));
	i = -1;
	strslen = 0;
	while (++i < size)
		strslen += ft_strlen(*(strs + i));
	seplen = ft_strlen(sep);
	ptr = malloc(strslen + seplen * (size - 1) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat(ptr, *(strs + i));
		if (i != size - 1)
			ft_strcat(ptr, sep);
		i++;
	}
	*(ptr + strslen + seplen * (size - 1)) = '\0';
	return (ptr);
}
