/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:41:33 by slyu              #+#    #+#             */
/*   Updated: 2022/01/05 19:41:36 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && *(haystack + i) != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (haystack[i + j] == needle[j] && i + j < len
				&& needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
