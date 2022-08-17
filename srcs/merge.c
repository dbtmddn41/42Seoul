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
#include <stdio.h>

void	three2one(t_deque *to_from[2], char to_a, int up, int limit[3])
{
	int	m;
	int	data[3];

	while (limit[0] || limit[1] || limit[2])
	{
		if (limit[0])
			data[0] = to_from[1]->rear->data;
		if (limit[1])
			data[1] = to_from[1]->front->data;
		if (limit[2])
			data[2] = to_from[0]->front->data;
		m = get_m(data, limit, up);
		if (m == 2)
			reverse_rotate(to_from[0], to_a);
		else
		{
			if (m == 1)
				reverse_rotate(to_from[1], !to_a);
			push(to_from[0], to_from[1], to_a);
		}
		if (limit[m] > 0)
			limit[m]--;
	}
}

int	get_m(int data[3], int limit[3], int up)
{
	int	i;
	int	m;
	int	m_idx;

	i = 0;
	if (up)
		m = -__INT32_MAX__ - 1;
	else
		m = __INT32_MAX__;
	while (i < 3)
	{
		if (limit[i])
		{
			if ((m < data[i]) == up || m == data[i])
			{
				m = data[i];
				m_idx = i;
			}
		}
		i++;
	}
	return (m_idx);
}

void	merge(t_deque *to_from[2], int **pattern, char to_a, int step)
{
	int	i;
	int	tri_num;
	int	limit[3];

	if (step < 1)
		return ;
	tri_num = ft_pow(3, step - 1);
	i = -1;
	while (++i < tri_num / 3 * 2 || (tri_num == 1 && i < tri_num))
	{
		limit[0] = ft_abs(pattern[step][tri_num * 2 - 1 - i]);
		limit[1] = ft_abs(pattern[step][i]);
		limit[2] = ft_abs(pattern[step][tri_num * 2 + i]);
		three2one(to_from, to_a, pattern[step - 1][i] > 0, limit);
	}
	move(to_from, pattern, to_a, step);
	while (i < tri_num)
	{
		limit[0] = ft_abs(pattern[step][tri_num / 3 + i]);
		limit[2] = ft_abs(pattern[step][i]);
		limit[1] = ft_abs(pattern[step][tri_num * 2 + i]);
		three2one(to_from, to_a, pattern[step - 1][i] > 0, limit);
		i++;
	}
	merge(to_from, pattern, to_a, step - 1);
}

void	move(t_deque *to_from[2], int **pattern, char to_a, int step)
{
	int	move_num;
	int	i;
	int	tri_num;

	if (step == 1)
		return ;
	move_num = 0;
	tri_num = ft_pow(3, step - 1);
	i = tri_num;
	while (i < tri_num / 3 * 4)
		move_num += ft_abs(pattern[step][i++]);
	while (move_num > 0)
	{
		push(to_from[0], to_from[1], to_a);
		move_num--;
	}
	to_a = !to_a;
	ft_swap((void **)to_from, (void **)(to_from + 1));
}
