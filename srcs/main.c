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
	char	**args;

	dq_init(&a);
	dq_init(&b);
	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	i = 0;
	while (i < argc - 1 || (argc == 2 && args[i] != NULL))
	{
		check_push_arg(&a, args[i], ft_atoi2(args[i]));
		i++;
	}
	if (!is_sorted(&a))
		push_swap(&a, &b, i);
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
	to_from[0] = a;
	to_from[1] = b;
	if (steps % 2 == 0)
	{
		ft_swap((void **)to_from, (void **)to_from + 1);
	}
	devide(to_from, pattern, n, steps--);
	merge(to_from, pattern, steps % 2, steps);
	delete_all(pattern);
}
