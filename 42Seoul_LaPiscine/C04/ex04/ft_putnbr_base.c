/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:37:24 by slyu              #+#    #+#             */
/*   Updated: 2021/09/21 18:39:29 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nb, char *base);
void	print_num(unsigned int num, char *base, int base_num);
int		check_base(char *base);

void	ft_putnbr_base(int nb, char *base)
{
	int				base_num;
	unsigned int	num;

	base_num = check_base(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		num = nb * (-1);
	}
	else
		num = nb;
	print_num(num, base, base_num);
}

void	print_num(unsigned int num, char *base, int base_num)
{
	if (num == 0)
		return ;
	print_num(num / base_num, base, base_num);
	write(1, base + (num % base_num), 1);
}

int	check_base(char *base)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	size = 0;
	while (*(base + size) != '\0')
	{
		if (*(base + size) == '+' || *(base + size) == '-')
			return (0);
		size++;
	}
	if (size < 2)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (size);
}
