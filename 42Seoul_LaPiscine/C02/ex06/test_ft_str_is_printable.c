/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:43:55 by slyu              #+#    #+#             */
/*   Updated: 2021/09/14 19:08:51 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	check;

	check = 1;
	while (*str != '\0')
	{
		if (*str < ' ' || *str > '~')
			check = 0;
		str++;
	}
	return (check);
}

int main()
{
	printf("%d", ft_str_is_printable(" sdf@\x12"));
	return 0;
}

