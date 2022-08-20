/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:08:31 by slyu              #+#    #+#             */
/*   Updated: 2022/08/19 01:08:36 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;
	int		i;
	char	**args;

	dq_init(&a);
	dq_init(&b);
	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if (args == NULL || argc == 1)
		return (-1);
	i = 0;
	while (i < argc - 1 || (argc == 2 && args[i] != NULL))
	{
		check_push_arg(&a, args[i], ft_atoi2(args[i]));
		i++;
	}
	read_inst(&a, &b);
	delete_dq(&a);
	delete_dq(&b);
	if (argc == 2)
		delete_all((void **)args);
}

int	execute(t_deque *a, t_deque *b, char *oper)
{
	int				res;

	if (!ft_strncmp(oper, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(oper, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(oper, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(oper, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(oper, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(oper, "pb\n", 3))
		pb(a, b);
	else
	{
		res = execute2(a, b, oper);
		if (res == -1)
		{
			ft_printf("execute: %s", oper);
			return (-1);
		}
	}
	return (0);
}

int	execute2(t_deque *a, t_deque *b, char *oper)
{
	if (!ft_strncmp(oper, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(oper, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(oper, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(oper, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(oper, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(oper, "rrr\n", 4))
		rrr(a, b);
	else
		return (-1);
	return (0);
}

void	read_inst(t_deque *a, t_deque *b)
{
	char	*oper;
	int		res;
	char	*tmp;

	while (1)
	{
		oper = get_next_line(0);
		if (!oper)
			break ;
		while (oper[ft_strlen(oper) - 1] != '\n')
		{
			tmp = get_next_line(0);
			if (tmp)
				oper = ft_strjoin(oper, tmp);
		}
		res = execute(a, b, oper);
		if (res == -1)
			checker_error(a, b);
	}
	if (is_sorted(a) && is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	checker_error(t_deque *a, t_deque *b)
{
	delete_dq(a);
	delete_dq(b);
	error_handler();
}