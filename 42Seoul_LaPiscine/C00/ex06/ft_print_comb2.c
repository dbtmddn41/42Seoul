/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:46:52 by slyu              #+#    #+#             */
/*   Updated: 2021/09/12 13:16:40 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	print_nums(int	first, int	second);

void	print_nums(int	first, int	second)
{
	char	first_10;
	char	first_1;
	char	second_10;
	char	second_1;
	char	space;

	space = ' ';
	first_10 = first / 10 + 0x30;
	first_1 = first % 10 + 0x30;
	second_10 = second / 10 + 0x30;
	second_1 = second % 10 + 0x30;
	write(1, &first_10, 1);
	write(1, &first_1, 1);
	write(1, &space, 1);
	write(1, &second_10, 1);
	write(1, &second_1, 1);
}

void	ft_print_comb2(void)
{
	int		first;
	int		second;
	char	space;
	char	comma;

	space = ' ';
	comma = ',';
	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			print_nums(first, second);
			if (first != 98 || second != 99)
			{
				write(1, &comma, 1);
				write(1, &space, 1);
			}
			second++;
		}
		first++;
	}
}
