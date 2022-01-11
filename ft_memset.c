/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:13:09 by slyu              #+#    #+#             */
/*   Updated: 2022/01/06 03:13:14 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		*((unsigned char *)(dest) + i) = (unsigned char) c;
		i++;
	}
	return (dest);
}
