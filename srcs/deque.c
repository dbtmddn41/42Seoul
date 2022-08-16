/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:35:14 by slyu              #+#    #+#             */
/*   Updated: 2022/08/09 23:35:16 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dnode	*create_node(int data, t_dnode *prev, t_dnode *next)
{
	t_dnode	*new_node;

	new_node = malloc(sizeof(t_dnode));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->prev = prev;
	new_node->next = next;
	return (new_node);
}

int	dqadd_front(t_deque *deque, int data)
{
	t_dnode	*new_node;
	t_dnode	*ex_front;

	if (!deque)
		return (-1);
	ex_front = deque->front;
	new_node = create_node(data, NULL, ex_front);
	if (!new_node)
		return (-1);
	if (ex_front)
		ex_front->prev = new_node;
	else
	{
		deque->front = new_node;
		deque->rear = new_node;
	}
	deque->front = new_node;
	return (0);
}

int	dqadd_back(t_deque *deque, int data)
{
	t_dnode	*new_node;
	t_dnode	*ex_rear;

	if (!deque)
		return (-1);
	ex_rear = deque->rear;
	new_node = create_node(data, ex_rear, NULL);
	if (!new_node)
		return (-1);
	if (ex_rear)
		ex_rear->next = new_node;
	else
	{
		deque->front = new_node;
		deque->rear = new_node;
	}
	deque->rear = new_node;
	return (0);
}

int	dqdel_front(t_deque *deque)
{
	t_dnode	*ex_front;
	int		data;

	ex_front = deque->front;
	data = ex_front->data;
	deque->front = ex_front->next;
	if (!(deque->front))
		deque->rear = NULL;
	else
		deque->front->prev = NULL;
	ex_front->next = NULL;
	free(ex_front);
	return (data);
}

int	dqdel_back(t_deque *deque)
{
	t_dnode	*ex_rear;
	int		data;

	ex_rear = deque->rear;
	data = ex_rear->data;
	deque->rear = ex_rear->prev;
	if (!(deque->rear))
		deque->front = NULL;
	else
		deque->rear->next = NULL;
	ex_rear->prev = NULL;
	free(ex_rear);
	return (data);
}
