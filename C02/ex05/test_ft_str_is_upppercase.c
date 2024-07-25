/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_upppercase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:39:12 by slyu              #+#    #+#             */
/*   Updated: 2021/09/14 18:40:17 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	check;

	check = 1;
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
			check = 0;
		str++;
	}
	return (check);
}

int main()
{
	printf("%d", ft_str_is_uppercase(""));
	return 0;
}

