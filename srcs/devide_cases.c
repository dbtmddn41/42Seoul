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
	else if (pat == 6)
		case6(to, from, to_a, 1);
	else if (pat == -6)
		case6(to, from, to_a, 0);
}

void	small_cases(t_deque *a, t_deque *b, int n, int up)
{
	if (n == 2)
	{
		if ((a->front->data < a->rear->data) == up)
			swap(a, up);
	}
	else if (n == 3)
		small_case3(a, up);
	else if (n >= 4 && n <= 6)
		small_case456(a, b, n);
}

void	small_case456(t_deque *a, t_deque *b, int n)
{
	int		i;
	int		limit[3];
	t_deque	*a_b[2];

	i = -1;
	while (++i < n - 3)
		push(b, a, 0);
	small_case3(a, 1);
	small_cases(b, a, n - 3, 0);
	limit[0] = n - 3;
	limit[1] = 0;
	limit[2] = 3;
	a_b[0] = a;
	a_b[1] = b;
	three2one(a_b, 1, 1, limit);
}

void	small_case3(t_deque *a, int up)
{
	int	data[3];
	int	m;
	int	lim[3];

	data[0] = a->front->data;
	data[1] = a->front->next->data;
	data[2] = a->rear->data;
	lim[0] = 1;
	lim[1] = 1;
	lim[2] = 1;
	m = get_m(data, lim, up);
	if (m == 2)
		rotate(a, up);
	else if (m == 1)
		reverse_rotate(a, up);
	lim[1]--;
	if ((a->rear->data > a->rear->prev->data) == up)
		swap(a, up);
}

void	swap_below(t_deque *to, char to_a)
{
	reverse_rotate(to, to_a);
	reverse_rotate(to, to_a);
	swap(to, to_a);
	rotate(to, to_a);
	rotate(to, to_a);
}
