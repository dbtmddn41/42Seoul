/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:28:05 by slyu              #+#    #+#             */
/*   Updated: 2021/11/23 17:28:10 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (*(s1 + i) != '\0' && i + 1 < n)
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		i++;
	}
	return ((unsigned char) *(s1 + i) - (unsigned char) *(s2 + i));
}
