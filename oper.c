/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoel.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:15:56 by slyu              #+#    #+#             */
/*   Updated: 2022/08/14 16:15:57 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	t_dnode	*rear_pre;
	t_dnode	*ex_rear;

	ex_rear = dqdel_back_node(a);
	rear_pre = dqdel_back_node(a);
	if (!ex_rear || !rear_pre)
	{
		dqadd_back_node(a, rear_pre);
		dqadd_back_node(a, ex_rear);
	}
	dqadd_back_node(a, ex_rear);
	dqadd_back_node(a, rear_pre);
}

void	sb(t_deque *b)
{
	sa(b);
}

void	ss(t_deque *a, t_deque *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
	opers++;
}

void	pa(t_deque *a, t_deque *b)
{
	t_dnode	*b_rear;

	b_rear = dqdel_back_node(b);
	if (!b_rear)
		return ;
	dqadd_back_node(a, b_rear);
}

void	pb(t_deque *a, t_deque *b)
{
	pa(b, a);
}
