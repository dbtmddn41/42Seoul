/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:35:36 by slyu              #+#    #+#             */
/*   Updated: 2021/09/12 20:51:12 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int	nb);
void	make_nbr(int	nb, int	i);

void	ft_putnbr(int	nb)
{
	int		i;

	i = 1000000000;
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		else
			nb *= -1;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (!(nb / i))
		i /= 10;
	make_nbr(nb, i);
}

void	make_nbr(int	nb, int i)
{
	char	number;

	if (i < 1)
		return ;
	number = nb / i + 0x30;
	write(1, &number, 1);
	make_nbr(nb - (nb / i) * i, i / 10);
	return ;
}
