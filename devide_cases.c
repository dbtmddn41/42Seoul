/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   devide_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:58:06 by slyu              #+#    #+#             */
/*   Updated: 2022/08/14 19:58:07 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cases(t_deque *to, t_deque *from, char to_a, int pat)
{
	if (pat == 2)
		case2(to, from, to_a, 1);
	else if (pat == -2)
		case2(to, from, to_a, 0);
	else if (pat == 3)
		case3(to, from, to_a, 1);
	else if (pat == -3)
		case3(to, from, to_a, 0);
	else if (pat == 4)
		case4(to, from, to_a, 1);
	else if (pat == -4)
		case4(to, from, to_a, 0);
	else if (pat == 5)
		case5(to, from, to_a, 1);
	else if (pat == -5)
		case5(to, from, to_a, 0);
}

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
	if ((to->front->data < to->front->prev->data) == up)
		swap(to, to_a);
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
	t_deque	*to_from[1];

	if ((from->rear->data < from->rear->prev->data) == up)
		swap(from, !to_a);
	if ((to->front->data < to->front->prev->data) == up)
		swap(to, to_a);
	limit[0] = 2;
	limit[1] = 1;
	limit[2] = 2;
	to_from[0] = to;
	to_from[1] = from;
	three2one(to_from, to_a, up, limit);
}
