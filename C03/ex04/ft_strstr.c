/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:20:16 by slyu              #+#    #+#             */
/*   Updated: 2021/09/20 02:59:54 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		i = 0;
		if (*str == *to_find)
		{
			while (*str == *(to_find + i) && *str != '\0')
			{
				str++;
				i++;
			}
		}
		if (*(to_find + i) == '\0')
			return (str - i);
		str++;
	}
	return ('\0');
}

int	main(void)
{
	printf("%s\n", ft_strstr("hello my love", ""));
	printf("%s", strstr("hello my love", ""));
}
