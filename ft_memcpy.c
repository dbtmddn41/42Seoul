/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:12:58 by slyu              #+#    #+#             */
/*   Updated: 2022/01/06 03:13:03 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned int	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < count)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
