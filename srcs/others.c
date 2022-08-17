/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:07:04 by slyu              #+#    #+#             */
/*   Updated: 2022/08/17 00:07:07 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_deque *dq)
{
	t_dnode	*curr;
	int		next_data;

	curr = dq->front;
	if (curr == NULL || curr->next == NULL)
		return (1);
	next_data = curr->next->data;
	while (curr != NULL)
	{
		if (curr->data < next_data)
			return (0);
		curr = curr->next;
		if (curr->next == NULL)
			break ;
		next_data = curr->next->data;
	}
	return (1);
}

void	store_oper(char *op)
{
	static char	*opers[100];
	static int	i = 0;

	if (op == NULL)
	{
		print_oper(i, opers);
		i = 0;
		return ;
	}
	opers[i] = op;
	i++;
	if (i >= 100)
	{
		print_oper(i, opers);
		i = 0;
	}
}

void	print_oper(int op_n, char *opers[])
{
	int		i;
	char	cmp;

	i = 0;
	while (i < op_n - 1)
	{
		if (opers[i][0] != 'p')
		{
			cmp = ft_strncmp(opers[i], opers[i + 1], 3);
			if ((cmp == 'a' - 'b' || cmp == 'b' - 'a')
				&& opers[i][0] == opers[i + 1][0])
			{
				write(1, opers[i], ft_strlen(opers[i]) - 2);
				write(1, opers[i], 1);
				write(1, "\n", 1);
				i += 2;
				continue ;
			}
		}
		ft_putstr_fd(opers[i], 1);
		i++;
	}
	if (i == op_n - 1)
		ft_putstr_fd(opers[i], 1);
}

void	error_handler(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

int	check_dupli(t_deque *dq, int num)
{
	t_dnode	*curr;

	curr = dq->front;
	while (curr != NULL)
	{
		if (num == curr->data)
			return (-1);
		curr = curr->next;
	}
	return (0);
}
