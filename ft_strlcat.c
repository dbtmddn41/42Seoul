/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:50:41 by slyu              #+#    #+#             */
/*   Updated: 2021/11/23 15:50:45 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	destlen;
	unsigned int	srclen;

	j = 0;
	while (*(src + j) != '\0')
		j++;
	srclen = j;
	i = 0;
	while (*(dst + i) != '\0' && i < dstsize)
		i++;
	if (i == dstsize)
		return (srclen + dstsize);
	else
		destlen = i;
	j = 0;
	while (*(src + j) != '\0' && i + 1 < dstsize)
	{
		*(dst + i) = *(src + j);
		i++;
		j++;
	}
	*(dst + i) = '\0';
	return (srclen + destlen);
}
