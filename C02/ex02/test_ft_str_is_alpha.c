/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:50:10 by slyu              #+#    #+#             */
/*   Updated: 2021/09/14 17:58:59 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	check;

	check = 1;
	while (*str != '\0')
	{
		if (*str < 'A')
			check = 0;
		else if (*str < 'a' && *str > 'Z')
			check = 0;
		else if (*str > 'z')
			check = 0;
		str++;
	}
	return (check);
}

int	main()
{
	printf("%d", ft_str_is_alpha(""));
	return 0;
}
