/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:40:05 by slyu              #+#    #+#             */
/*   Updated: 2021/09/24 00:24:01 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_sqrt(int nb)
{
        int     n;

        n = 1;
        while (n * n > 0 && n * n < nb)
                n++;
	return (n - 1);
}

int ft_is_prime(int nb)
{
	int	n;
	int	check;
	int	sqrt;

	if (nb < 2)
		return (0);
	sqrt = ft_sqrt(nb);
	n = 2;
	check = 1;
	while (n <= sqrt)
	{
		if (nb % n == 0)
		{
			check = 0;
			break ;
		}
		n++;
	}
	return (check);
}

#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	printf("%d", ft_is_prime(atoi(argv[1])));
}
