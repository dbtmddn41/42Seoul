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

	dq_init(&a);
	dq_init(&b);
	i = 1;
	while (i < argc)
	{
		//무결성 검증
		dqadd_back(&a, atoi(argv[i]));
		i++;
	}
	push_swap(&a, &b, --i);

	delete_dq(&a);
	delete_dq(&b);
}

void	print_deque(t_deque *d)
{
	t_dnode *curr = d->front;

	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

void	push_swap(t_deque *a, t_deque *b, int n)
{
	int		**pattern;
	int		steps;

	steps = log_int(3, n / 2) + 1;
	pattern = calc_pattern(n, steps);
	for (int i = 0; i < steps; i++)
	{
		for (int j = 0; j < ft_pow(3, i); j++)
		{
			printf("%d ", pattern[i][j]);
		}
		printf("\n");
	}
	devide(a, b, pattern, n);
	print_deque(a);
	print_deque(b);
	//merge(a, b, pattern, n);
}

