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
int	opers = 0;

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
		dqadd_front(&a, atoi(argv[i]));
		i++;
	}
	push_swap(&a, &b, --i);
	write(1, "the end\n", 9);
	print_deque(&a);
	print_deque(&b);
	delete_dq(&a);
	delete_dq(&b);
	//printf("opers: %d", opers);
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
	t_deque	*to_from[2];

	steps = log_int(3, n / 2) + 1;
	pattern = calc_pattern(n, steps);
	/*for (int i = 0; i < steps; i++)
	{
		for (int j = 0; j < ft_pow(3, i); j++)
			printf("%d ", pattern[i][j]);
		printf("\n");
	}*/
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
	//write(1, "=======================\n", 25);
	merge(to_from, pattern, steps % 2, steps);
}

