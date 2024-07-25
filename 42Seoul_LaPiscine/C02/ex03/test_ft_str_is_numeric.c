/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:02:33 by slyu              #+#    #+#             */
/*   Updated: 2021/09/14 18:07:51 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	check;

	check = 1;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			check = 0;
		str++;
	}
	return (check);
}

int	main()
{
	printf("%d", ft_str_is_numeric(""));
	return (0);
}
