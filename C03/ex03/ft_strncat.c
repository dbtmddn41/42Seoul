/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:46:28 by slyu              #+#    #+#             */
/*   Updated: 2021/09/20 01:41:21 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int j;

	i = 0;
	while (*(dest + i) != '\0')
		i++;
	j = 0;
	while (*src != '\0' && j < nb)
	{
		*(dest + i) = *src;
		src++;
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (dest);
}

int	main(void)
{
	char	happy[30] = "happydayihahaahahaa";
	happy[6] = '\0';
	printf("%s%c\n", ft_strncat(happy, "life", 5), happy[12]);
	printf("%s", strncat(happy, "life", 4));
}
