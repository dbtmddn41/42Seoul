/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:14:30 by slyu              #+#    #+#             */
/*   Updated: 2021/09/24 00:42:51 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);
int	ft_is_prime(int nb);

int     ft_sqrt(int nb)
{
        int     n;

        n = 1;
        while (n * n > 0 && n * n <= nb)
                n++;
        return (n - 1);
}

int ft_is_prime(int nb)
{
        int     n;
        int     check;
        int     sqrt;

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

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	else if (nb % 2)
		return ft_find_next_prime(nb + 2);
	else
		return ft_find_next_prime(nb + 1);

}

#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	printf("%d", ft_find_next_prime(atoi(argv[1])));
}
