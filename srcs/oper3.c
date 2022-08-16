/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoel.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:31:28 by slyu              #+#    #+#             */
/*   Updated: 2022/08/14 17:31:29 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *a)
{
	t_dnode	*ex_front;

	ex_front = dqdel_front_node(a);
	if (!ex_front)
		return ;
	dqadd_back_node(a, ex_front);	
}

void	rrb(t_deque *b)
{
	rra(b);
}

void	rrr(t_deque *a, t_deque *b)
{
	rra(a);
	rrb(b);
	store_oper("rrr\n");
	opers++;
}

void	push(t_deque *to, t_deque *from, char to_a)
{
	if (to_a)
	{
		pa(to, from);
		store_oper("pa\n");
	}
	else
	{
		pb(from, to);
		store_oper("pb\n");	
	}
	opers++;
}

void	reverse_rotate(t_deque *to, char for_a)
{
	if (for_a)
	{
		rra(to);
		store_oper("rra\n");	
	}
	else
	{
		rrb(to);
		store_oper("rrb\n");
	}
	opers++;
}