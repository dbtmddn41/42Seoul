/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:01:18 by slyu              #+#    #+#             */
/*   Updated: 2022/02/14 18:54:13 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*make_numstr(char *num_str, unsigned int n, int jarisu)
{
	unsigned int	i;
	int				index;

	i = 1;
	index = 0;
	while (jarisu > 1)
	{
		i *= 10;
		jarisu--;
	}
	while (i > 0)
	{
		num_str[index] = n / i + '0';
		n %= i;
		i /= 10;
		index++;
	}
	num_str[index] = '\0';
	return (num_str);
}

int	check_jarisu(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_nosign(int n)
{
	unsigned int	abs_n;
	char			*num_str;
	int				jarisu;

	if (n < 0)
		abs_n = (-1) * n;
	else
		abs_n = n;
	jarisu = check_jarisu(abs_n);
	num_str = (char *)malloc(jarisu + 1);
	if (!num_str)
		return (0);
	return (make_numstr(num_str, abs_n, jarisu));
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		jarisu;
	char	*num_str;

	jarisu = check_jarisu(n);
	num_str = (char *)malloc(jarisu + 1);
	if (!num_str)
		return (0);
	return (make_numstr(num_str, n, jarisu));
}
