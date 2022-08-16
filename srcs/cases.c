/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:59:14 by slyu              #+#    #+#             */
/*   Updated: 2022/08/16 23:59:16 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case2(t_deque *to, t_deque *from, char to_a, int up)
{
	if ((to->front->data > from->rear->data) == up)
	{
		reverse_rotate(to, to_a);
		push(to, from, to_a);
	}
	else
	{
		push(to, from, to_a);
		reverse_rotate(to, to_a);
	}
}

void	case3(t_deque *to, t_deque *from, char to_a, int up)
{
	if ((from->rear->data < from->rear->prev->data) == up)
		swap(from, !to_a);
	if ((from->rear->data > to->front->data) == up)
	{
		push(to, from, to_a);
		if ((from->rear->data > to->front->data) == up)
		{
			push(to, from, to_a);
			reverse_rotate(to, to_a);
		}
		else
		{
			reverse_rotate(to, to_a);
			push(to, from, to_a);
		}
	}
	else
	{
		reverse_rotate(to, to_a);
		push(to, from, to_a);
		push(to, from, to_a);
	}
}

void	case4(t_deque *to, t_deque *from, char to_a, int up)
{
	int		limit[3];
	t_deque	*to_from[2];

	if ((from->rear->data < from->rear->prev->data) == up)
		swap(from, !to_a);
	if ((to->front->data < to->front->next->data) == up)
	{
		reverse_rotate(to, to_a);
		reverse_rotate(to, to_a);
		swap(to, to_a);
		rotate(to, to_a);
		rotate(to, to_a);
	}
	limit[0] = 2;
	limit[1] = 0;
	limit[2] = 2;
	to_from[0] = to;
	to_from[1] = from;
	three2one(to_from, to_a, up, limit);
}

void	case5(t_deque *to, t_deque *from, char to_a, int up)
{
	int		limit[3];
	t_deque	*to_from[2];

	if ((from->rear->data < from->rear->prev->data) == up)
		swap(from, !to_a);
	if ((to->front->data < to->front->next->data) == up)
	{
		reverse_rotate(to, to_a);
		reverse_rotate(to, to_a);
		swap(to, to_a);
		rotate(to, to_a);
		rotate(to, to_a);
	}
	limit[0] = 2;
	limit[1] = 1;
	limit[2] = 2;
	to_from[0] = to;
	to_from[1] = from;
	three2one(to_from, to_a, up, limit);
}

void	case6(t_deque *to, t_deque *from, char to_a, int up)
{
	int		limit[3];
	t_deque	*to_from[2];

	if ((from->rear->data < from->rear->prev->data) == up)
		swap(from, !to_a);
	if ((to->front->data < to->front->next->data) == up)
	{
		reverse_rotate(to, to_a);
		reverse_rotate(to, to_a);
		swap(to, to_a);
		rotate(to, to_a);
		rotate(to, to_a);
	}
	if ((from->front->data < from->front->next->data) == up)
	{
		reverse_rotate(from, !to_a);
		reverse_rotate(from, !to_a);
		swap(from, !to_a);
		rotate(from, !to_a);
		rotate(from, !to_a);
	}
	limit[0] = 2;
	limit[1] = 2;
	limit[2] = 2;
	to_from[0] = to;
	to_from[1] = from;
	three2one(to_from, to_a, up, limit);
}
