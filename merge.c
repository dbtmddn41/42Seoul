/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:30:42 by slyu              #+#    #+#             */
/*   Updated: 2022/08/10 00:30:43 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three2one(t_deque *to_from[2], char to_a, int up, int limit[3])
{
	int	m;
	int	data[3];

	data[0] = to_from[1]->rear->data;
	data[1] = to_from[1]->front->data;
	data[2] = to_from[0]->front->data;
	while (limit[0] || limit[1] || limit[2])
	{
		m = get_m(data, limit, up);	 
		if (m == 2)
			reverse_rotate(to_from[0], to_a);
		else
		{
			if (m == 0)
				reverse_rotate(to_from[1], !to_a);
			push(to_from[0], to_from[1], to_a);
		}
		limit[m]--;
	}
}

int	get_m(int data[3], int limit[3], int up)
{
	int	i;
	int	m;
	int	m_idx;

	if (up)
	{
		m = INT32_MIN;
		while (i < 3)
		{
			if (limit[i])
				if (m < data[i])
				{
					m = data[i];
					m_idx = i;
				}
		}
	}
	else
	{
		m = INT32_MAX;
		while (i < 3)
		{
			if (limit[i])
				if (m > data[i])
				{
					m = data[i];
					m_idx = i;
				}
		}
	}
	return (i);
}

void	merge_operate(t_deque *to, t_deque *from, char to_a, int oper_num)
{
		if (oper_num == 2)
			reverse_rotate(to, to_a);
		else
		{
			if (oper_num == 0)
				reverse_rotate(from, !to_a);
			push(to, from, to_a);
		}
}