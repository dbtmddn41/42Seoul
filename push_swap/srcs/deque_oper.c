/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoel.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:57:58 by slyu              #+#    #+#             */
/*   Updated: 2022/08/14 16:57:59 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dqadd_front_node(t_deque *deque, t_dnode *node)
{
	t_dnode	*ex_front;

	if (!deque || !node)
		return ;
	ex_front = deque->front;
	node->next = ex_front;
	node->prev = NULL;
	if (ex_front)
		ex_front->prev = node;
	else
		deque->rear = node;
	deque->front = node;
}

void	dqadd_back_node(t_deque *deque, t_dnode *node)
{
	t_dnode	*ex_rear;

	if (!deque || !node)
		return ;
	ex_rear = deque->rear;
	node->prev = ex_rear;
	node->next = NULL;
	if (ex_rear)
		ex_rear->next = node;
	else
		deque->front = node;
	deque->rear = node;
}

t_dnode	*dqdel_front_node(t_deque *deque)
{
	t_dnode	*ex_front;

	if (!deque)
		return (0);
	ex_front = deque->front;
	if (!ex_front)
		return (0);
	if (ex_front->next)
		ex_front->next->prev = NULL;
	else
		deque->rear = NULL;
	deque->front = ex_front->next;
	return (ex_front);
}

t_dnode	*dqdel_back_node(t_deque *deque)
{
	t_dnode	*ex_rear;

	if (!deque)
		return (0);
	ex_rear = deque->rear;
	if (!ex_rear)
		return (0);
	if (ex_rear->prev)
		ex_rear->prev->next = NULL;
	else
		deque->front = NULL;
	deque->rear = ex_rear->prev;
	return (ex_rear);
}

void	delete_dq(t_deque *dq)
{
	t_dnode	*tmp;
	t_dnode	*curr;

	curr = dq->front;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		tmp->next = NULL;
		tmp->prev = NULL;
		free(tmp);
	}
	dq->front = NULL;
	dq->rear = NULL;
}
