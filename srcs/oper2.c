/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoel.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:43:20 by slyu              #+#    #+#             */
/*   Updated: 2022/08/14 16:43:22 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	t_dnode	*ex_rear;

	ex_rear = dqdel_back_node(a);
	if (!ex_rear)
		return ;
	dqadd_front_node(a, ex_rear);
}

void	rb(t_deque *b)
{
	ra(b);
}

void	rr(t_deque *a, t_deque *b)
{
	ra(a);
	rb(b);
}

void	rotate(t_deque *to, char for_a)
{
	if (for_a)
	{
		ra(to);
		store_oper("ra\n");
	}
	else
	{
		rb(to);
		store_oper("rb\n");
	}
}

void	swap(t_deque *to, char for_a)
{
	if (for_a)
	{
		sa(to);
		store_oper("sa\n");
	}
	else
	{
		sb(to);
		store_oper("sb\n");
	}
}
