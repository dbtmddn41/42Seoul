/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:33:29 by slyu              #+#    #+#             */
/*   Updated: 2022/08/11 18:33:31 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	devide(t_deque *to_from[2], int **pattern, int n, int steps)
{
	int		small_num;
	int		i;
	int		tri_num;
	char	to_a;

	small_num = calc_small(pattern, steps);
	to_a = steps % 2;
	if (to_a)
		small_num = n - small_num;
	while (small_num-- > 0)
		push(to_from[(int)to_a], to_from[(int) !to_a], 0);
	tri_num = ft_pow(3, steps - 1);
	i = -1;
	while (++i < tri_num)
	{
		cases(to_from[0], to_from[1], to_a, pattern[steps - 1][i]);
		if (i + 1 == tri_num / 3 * 2)
		{
			small_num = calc_small2(pattern, steps) + 1;
			while (--small_num > 0)
				push(to_from[0], to_from[1], to_a);
			to_a = !to_a;
			ft_swap((void **)to_from, (void **)(to_from + 1));
		}
	}
}

int	calc_small(int **pattern, int steps)
{
	int	tri_num;
	int	res;
	int	i;

	tri_num = ft_pow(3, steps - 1);
	res = 0;
	i = -1;
	while (++i < tri_num * 2 / 3 || (tri_num == 1 && i < tri_num))
	{
		if (2 <= ft_abs(pattern[steps - 1][i])
			&& ft_abs(pattern[steps - 1][i]) <= 3)
			res += 1;
		else
			res += 2;
	}
	while (i < tri_num)
	{
		if (ft_abs(pattern[steps - 1][i]) == 5)
			res += 1;
		else if (ft_abs(pattern[steps - 1][i]) == 6)
			res += 2;
		i++;
	}
	return (res);
}

int	calc_small2(int **pattern, int steps)
{
	int	tri_num;
	int	res;
	int	element_num;
	int	i;

	tri_num = ft_pow(3, steps - 2);
	res = 0;
	i = tri_num * 2;
	while (i < tri_num * 3)
	{
		element_num = ft_abs(pattern[steps - 1][i]);
		if (2 == element_num)
			res += 1;
		else
			res += 2;
		i++;
	}
	return (res);
}
