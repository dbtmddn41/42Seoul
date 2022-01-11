/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:26:16 by slyu              #+#    #+#             */
/*   Updated: 2022/01/06 20:26:18 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_itoa(int n);

static char	*make_numstr(char *num_str, unsigned int n, int jarisu, int index)
{
	unsigned int	i;

	i = 1;
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

static int	check_jarisu(unsigned int n)
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

char	*ft_itoa(int n)
{
	unsigned int	abs_n;
	int				i;
	char			*num_str;
	int				jarisu;

	i = 0;
	if (n < 0)
	{
		abs_n = (-1) * n;
		i = -1;
	}
	else
		abs_n = n;
	jarisu = check_jarisu(abs_n);
	num_str = (char *) malloc(jarisu + 1 - i);
	if (!num_str)
		return (0);
	if (i == -1)
	{
		*num_str = '-';
		i = 1;
	}
	else
		i = 0;
	return (make_numstr(num_str, abs_n, jarisu, i));
}
