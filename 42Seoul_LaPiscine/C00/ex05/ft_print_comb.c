/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 03:19:34 by slyu              #+#    #+#             */
/*   Updated: 2021/09/12 13:23:12 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	put_number(char fisrt, char second, char third);

void	put_number(char first, char second, char third)
{
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	write(1, &first, 1);
	write(1, &second, 1);
	write(1, &third, 1);
	if (!(first == '7' && second == '8' && third == '9'))
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0';
	while (first <= '7')
	{
		second = first + 1;
		while (second <= '8')
		{
			third = second + 1;
			while (third <= '9')
			{
				put_number(first, second, third);
				third++;
			}
			second++;
		}
		first++;
	}
}
