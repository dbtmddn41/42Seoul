/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:32:00 by slyu              #+#    #+#             */
/*   Updated: 2021/09/19 20:44:16 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(dest + i) != '\0')
		i++;
	while (*src != '\0')
	{
		*(dest + i) = *src;
		i++;
		src++;
	}
	*(dest + i) = '\0';
	return (dest);
}

int	main(void)
{
	char	happy[30] = "happy";
	printf("%s\n", ft_strcat(happy, "life"));
	printf("%s", strcat(happy, "life"));
}
