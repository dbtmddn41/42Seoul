/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:54:21 by slyu              #+#    #+#             */
/*   Updated: 2021/09/21 13:10:23 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	print_num(unsigned int num);
void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	unsigned int	num;

	if (nb < 0)
	{
		write(1, "-", 1);
		num = (unsigned int)(nb * (-1));
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else
		num = (unsigned int) nb;
	print_num(num);
}

void	print_num(unsigned int num)
{
	if (num == 0)
		return ;
	print_num(num / 10);
	ft_putchar(num % 10 + 0x30);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
