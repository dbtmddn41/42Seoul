/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:47:41 by slyu              #+#    #+#             */
/*   Updated: 2021/09/12 18:23:02 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int	n);
void	make_combn(int	n, char	*num, int	i);
void	put_nums(char	*num, int	i);

void	ft_print_combn(int	n)
{
	char	num[10];
	int		index;
	int		i;

	index = 0;
	while (index < 10)
	{
		num[index] = index + 0x30;
		index++;
	}
	i = 0;
	make_combn(n, num, i);
}

void	make_combn(int	n, char	*num, int	i)
{
	if (n == 0)
		return ;
	while (num[i] <= 10 - n + 0x30)
	{
		num[i + 1] = num[i] + 1;
		make_combn(n - 1, num, i + 1);
		if (n == 1)
			put_nums(num, i);
		num[i]++;
	}
}

void	put_nums(char	*num, int	i)
{
	int		check;

	check = 1;
	write(1, num, i + 1);
	if (num[i] == '9')
	{
		while (i > 0)
		{
			check = (num[i - 1] == num[i] - 1) && check;
			i--;
		}
		if (check == 1)
			return ;
	}
	write(1, ", ", 2);
}
