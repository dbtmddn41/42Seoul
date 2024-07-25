/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:53:33 by slyu              #+#    #+#             */
/*   Updated: 2021/09/28 21:07:08 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*ptr;
	unsigned int	srclen;
	unsigned int	i;

	srclen = 0;
	i = 0;
	while (*(src + srclen) != '\0')
		srclen++;
	ptr = malloc(srclen + 1);
	if (!ptr)
		return (0);
	while (srclen > i)
	{
		*(ptr + i) = *(src + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
