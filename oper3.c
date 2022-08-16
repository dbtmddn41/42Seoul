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
	write(1, "rrr\n", 4);
	opers++;
}

void	push(t_deque *to, t_deque *from, char to_a)
{
	if (to_a)
	{
		pa(to, from);
		write(1, "pa\n", 3);
	}
	else
	{
		pb(from, to);
		write(1, "pb\n", 3);	
	}
	opers++;
}

void	reverse_rotate(t_deque *to, char for_a)
{
	if (for_a)
	{
		rra(to);
		write(1, "rra\n", 4);	
	}
	else
	{
		rrb(to);
		write(1, "rrb\n", 4);
	}
	opers++;
}