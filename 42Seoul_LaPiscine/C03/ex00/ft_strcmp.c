/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:54:59 by slyu              #+#    #+#             */
/*   Updated: 2021/09/16 19:11:55 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0' || *s2 == '\0')
			break ;
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	main(void)
{
	char	str1[10] = "hellod";
	char	str2[10] = "hellosf";

	int	n = ft_strcmp(str1, str2);
	printf("%d\n", n);
	n = strcmp(str1, str2);
	printf("%d", n);
	return (0);
}
