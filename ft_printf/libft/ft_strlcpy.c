/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:57:06 by slyu              #+#    #+#             */
/*   Updated: 2021/11/23 14:53:24 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (i + 1 < dstsize && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (dstsize != 0)
		*(dst + i) = '\0';
	while (*(src + i) != '\0')
		i++;
	return (i);
}
