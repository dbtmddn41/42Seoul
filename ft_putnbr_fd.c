/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:09:10 by slyu              #+#    #+#             */
/*   Updated: 2022/01/07 16:09:11 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd);

static void	print_num(unsigned int n, int fd)
{
	unsigned int	num;

	if (n == 0)
		return ;
	print_num(n / 10, fd);
	num = n % 10 + '0';
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_n;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		abs_n = n * (-1);
	}
	else
		abs_n = n;
	print_num(abs_n, fd);
}
