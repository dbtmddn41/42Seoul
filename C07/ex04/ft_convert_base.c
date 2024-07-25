/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:33:22 by slyu              #+#    #+#             */
/*   Updated: 2021/09/28 10:34:12 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_putnbr(int num, char *base_to, int base_num);
char	*ft_itoa_base(int num, char *base_to);
int		make_num(char *str, int base_num, char *base);
int		ft_atoi_base(char *str, char *base_to);
int		check_base(char *base);
int		check_size(int num, int base_num);
void	ft_rev(char *tab);

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == ' ' || c == '\f')
		return (1);
	else
		return (0);
}


int	check_zero(char *str, char *base)
{
	int		base_num;
	int		check;
	int		j;

	base_num = check_base(base);
	if (!base_num)
		return (0);
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
		str++;
	check = 0;
	while (*str == base[0])
		str++;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == ' ' || *str == '\f')
		str++;
		j = 0;
	while (base[j] != *str && j < base_num)
		j++;
	if (base_num == j)
		return (1);
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*ptr;

	if (check_zero(nbr, base_from))
		num = 0;
	else
	{
		num = ft_atoi_base(nbr, base_from);
		if (!num)
			return (0);
	}
	ptr = ft_itoa_base(num, base_to);
	return (ptr);
}

int	make_num(char *str, int base_num, char *base)
{
	int	num;
	int	j;

	num = 0;
	while (*str != '\0')
	{
		j = 0;
		while (base[j] != *str && j < base_num)
			j++;
		if (base_num == j)
			return (num);
		num = num * base_num + j;
		str++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int		buho;
	int		num;
	int		base_num;

	base_num = check_base(base);
	if (!base_num)
		return (0);
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == ' ' || *str == '\f')
		str++;
	buho = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			buho *= -1;
		str++;
	}
	num = make_num(str, base_num, base);
	return (num * buho);
}

int	check_base(char *base)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	size = 0;
	while (*(base + size) != '\0')
	{
		if (*(base + size) == '+' || *(base + size) == '-'
			|| is_space(*(base + size)))
			return (0);
		size++;
	}
	if (size < 2)
		return (0);
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (base[i] == base[j])
				return (0);
	}
	return (size);
}