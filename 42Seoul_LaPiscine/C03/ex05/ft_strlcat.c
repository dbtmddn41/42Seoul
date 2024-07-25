/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:37:39 by slyu              #+#    #+#             */
/*   Updated: 2021/09/21 02:05:16 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;
	int	destlen;
	int	srclen;

	j = 0;
	while (*(src + j) != '\0')
		j++;
	srclen = j;
	i = 0;
	while (*(dest + i) != '\0' && i < size)
		i++;
	if (i == size)
		return (srclen + size);
	else
		destlen = i;
	j = 0;
	while (*(src + j) != '\0' && i + 1 < size)
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (srclen + destlen);
}

int	main(void)
{
	char	str1[30] = "happy";
	char	str2[30] = "happy";
	char	life[] = "life";
	printf("%u\n", ft_strlcat(str1, life, 5));
	printf("%s\n", str1);
	printf("%lu\n", strlcat(str2, life, 5));
	printf("%s", str2);
}
