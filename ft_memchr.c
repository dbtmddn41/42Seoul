/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:00:54 by slyu              #+#    #+#             */
/*   Updated: 2022/01/05 19:00:58 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *) s;
	d = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*(str + i) == d)
			return (str + i);
		i++;
	}
	return (0);
}
