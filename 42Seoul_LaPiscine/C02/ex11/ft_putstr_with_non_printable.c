/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:17:33 by slyu              #+#    #+#             */
/*   Updated: 2021/09/16 17:00:23 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < ' ' || *str > '~')
		{
			ft_putchar('\\');
			ft_putchar(*str / 0x10 + 0x30);
			if (*str % 0x10 > 9)
				ft_putchar(*str % 0x10 + 0x57);
			else
				ft_putchar(*str % 0x10 + 0x30);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
