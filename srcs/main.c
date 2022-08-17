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

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;
	int		i;
	int		num;

	dq_init(&a);
	dq_init(&b);
	i = 1;
	while (i < argc)
	{
		num = ft_atoi2(argv[i]);
		if ((ft_strncmp(argv[i], "0", ft_strlen(argv[i])) && num == 0)
			|| (ft_strncmp(argv[i], "-1", ft_strlen(argv[i])) && num == -1)
			|| check_dupli(&a, num) == -1 || dqadd_front(&a, num) == -1)
		{
			delete_dq(&a);
			error_handler();
		}
		i++;
	}
	if (!is_sorted(&a))
		push_swap(&a, &b, --i);
	store_oper(NULL);
	delete_dq(&a);
	delete_dq(&b);
}

void	push_swap(t_deque *a, t_deque *b, int n)
{
	int		**pattern;
	int		steps;
	t_deque	*to_from[2];

	if (n <= 6)
	{
		small_cases(a, b, n, 1);
		return ;
	}
	steps = log_int(3, n / 2) + 1;
	pattern = calc_pattern(n, steps);
	if (!pattern)
		error_handler();
	if (steps % 2 == 0)
	{
		to_from[0] = b;
		to_from[1] = a;
	}
	else
	{
		to_from[0] = a;
		to_from[1] = b;
	}
	devide(to_from, pattern, n, steps--);
	merge(to_from, pattern, steps % 2, steps);
	delete_all(pattern);
}
