/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:40:19 by slyu              #+#    #+#             */
/*   Updated: 2021/09/28 10:31:31 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	size;
	unsigned int	i;

	size = max - min;
	if (max - min < 1)
		return (0);
	*range = malloc(sizeof(int) * size + 1);
	if (!range)
		return (-1);
	i = 0;
	while (i < size)
	{
		*(*range + i) = min + i;
		i++;
	}
	return ((int) size);
}
