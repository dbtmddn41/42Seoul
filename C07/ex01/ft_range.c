/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:12:51 by slyu              #+#    #+#             */
/*   Updated: 2021/09/27 18:43:26 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*ptr;
	unsigned int	size;
	unsigned int	i;

	size = max - min;
	if (max - min < 1)
		return (0);
	ptr = malloc(sizeof(int) * size + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < size)
	{
		*(ptr + i) = min + i;
		i++;
	}
	return (ptr);
}
