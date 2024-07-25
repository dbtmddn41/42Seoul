/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:11:17 by slyu              #+#    #+#             */
/*   Updated: 2021/09/16 17:53:31 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);
int		check_numalpha(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (*(str + i) >= 'a' && *(str + i) <= 'z')
		*(str + i) -= 0x20;
	while (*(str + i) != '\0')
	{
		i++;
		if (!check_numalpha(*(str + i - 1)))
		{
			if (*(str + i) >= 'a' && *(str + i) <= 'z')
				*(str + i) -= 0x20;
		}
		else if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) += 0x20;
	}
	return (str);
}

int	check_numalpha(char c)
{
	int	check;

	check = 0;
	if (c >= '0' && c <= '9')
		check = 1;
	else if (c >= 'A' && c <= 'Z')
		check = 1;
	else if (c >= 'a' && c <= 'z')
		check = 1;
	return (check);
}
