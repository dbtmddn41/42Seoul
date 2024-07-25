/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:42:47 by slyu              #+#    #+#             */
/*   Updated: 2021/09/14 17:40:26 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_strcpy(char *dest, char *src);

void	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = *(src + i);
	return dest;
}

int	main()
{
	char	*src = "hello";
	char	dest[10];

	printf("%p", dest);
	char *a = ft_strcpy(dest, src);
	printf("%s", dest);
	printf("%p", a);
	return (0);
}
