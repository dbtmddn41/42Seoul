/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:23:46 by slyu              #+#    #+#             */
/*   Updated: 2022/08/09 23:23:49 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;
	int		i;

	i = 1;
	while (i < argc)
	{
		//무결성 검증
		dqadd_back(&a, ft_atoi(argv[i]));
	}
	push_swap(&a, &b, --i);
	delete_dq(&a);
	delete_dq(&b);
}

void	push_swap(t_deque *a, t_deque *b, int n)
{
	int		**pattern;
	int		steps;

	steps = log_int(3, n / 3) + 1;
	pattern = calc_pattern(n, steps);
	devide(a, b, pattern, n);
	merge(a, b, pattern, n);
}