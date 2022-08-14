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

void	devide(t_deque *a, t_deque *b, int **pattern, int n)
{
	int		small_num;
	int		steps;
	int		i;
	t_deque	*to;
	t_deque *from;
	
	steps = log_int(3, n / 2) + 1;
	small_num = calc_small(pattern, steps);
	if (steps % 2 == 0)
	{
		to = b;
		from = a;
		i = small_num;
	}
	else
	{
		to = a;
		from = b;
		i = n - small_num;
	}
	while (i > 0)
	{
		push(b, a, 0);
		i--;
	}
	devide_process(to, from, pattern, steps);
}

void	devide_process(t_deque *to, t_deque *from, int **pattern, int steps)
{
	int		i;
	int		small_num;
	char	to_a;
	int		tri_num;
	t_deque *tmp;

	to_a = steps % 2;
	tri_num = ft_pow(3, steps - 1);
	i = 0;
	while (i < tri_num)
	{
		if (to < from)
		{
			print_deque(to);
			print_deque(from);
		}
		else{
			print_deque(from);
			print_deque(to);
		}
		cases(to, from, to_a, pattern[steps - 1][i]);
		i++;
		if (i == tri_num / 3 * 2)
		{
			small_num = calc_small2(pattern, steps);
			while (small_num > 0)
			{
				push(to, from, to_a);
				small_num--;
			}
			to_a = !to_a;
			ft_swap((void **)&from, (void **)&to);
		}
	}
}

int	calc_small(int **pattern, int steps)
{
	int tri_num;
	int	res;
	int	element_num;
	int	i;

	tri_num = ft_pow(3, --steps);
	res = 0;
	i = 0;
	while (i < tri_num * 2 / 3)
	{
		element_num = ft_abs(pattern[steps][i]);
		if (2 <= element_num && element_num <= 3)
			res += 1;
		else
			res += 2;
		i++;
	}
	while (i < tri_num)
	{
		element_num = ft_abs(pattern[steps][i]);
		if (element_num == 5)
			res += 1;
		i++;
	}
	return (res);
}

int	calc_small2(int **pattern, int steps)
{
	int tri_num;
	int	res;
	int	element_num;
	int	i;

	steps--;
	tri_num = ft_pow(3, steps - 1);
	res = 0;
	i = tri_num * 2;
	while (i < tri_num * 3)
	{
		element_num = ft_abs(pattern[steps][i]);
		if (3 <= element_num && element_num <= 6)
			res += 2;
		else
			res += 3;
		i++;
	}
	return (res);
}