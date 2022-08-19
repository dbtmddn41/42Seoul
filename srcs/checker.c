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
	t_list	*opers;
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
	opers = read_inst();
	if (opers)
		operate(&a, &b, opers);
	delete_dq(&a);
	delete_dq(&b);
	if (!opers)
		error_handler();
	ft_lstclear(&opers, free);
}

void	operate(t_deque *a, t_deque *b, t_list *opers)
{
	int		res;
	t_list	*curr;

	curr = opers;
	while (curr != NULL && curr->content != NULL)
	{
		res = execute(a, b, curr->content);
		if (res == -1)
		{
			delete_dq(a);
			delete_dq(b);
			ft_lstclear(&opers, free);
			error_handler();
		}
		curr = curr->next;
	}
	if (is_sorted(a) && is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	execute(t_deque *a, t_deque *b, char *oper)
{
	unsigned int	str_len;
	int				res;

	str_len = ft_strlen(oper);
	if (!ft_strncmp(oper, "sa\n", str_len))
		sa(a);
	else if (!ft_strncmp(oper, "sb\n", str_len))
		sb(b);
	else if (!ft_strncmp(oper, "sa\n", str_len))
		sa(a);
	else if (!ft_strncmp(oper, "ss\n", str_len))
		ss(a, b);
	else if (!ft_strncmp(oper, "pa\n", str_len))
		pa(a, b);
	else if (!ft_strncmp(oper, "pb\n", str_len))
		pb(a, b);
	else
	{
		res = execute2(a, b, oper, str_len);
		if (res == -1)
			return (-1);
	}
	return (0);
}

int	execute2(t_deque *a, t_deque *b, char *oper, unsigned int str_len)
{
	if (!ft_strncmp(oper, "ra\n", str_len))
		ra(a);
	else if (!ft_strncmp(oper, "rb\n", str_len))
		rb(b);
	else if (!ft_strncmp(oper, "rr\n", str_len))
		rr(a, b);
	else if (!ft_strncmp(oper, "rra\n", str_len))
		rra(a);
	else if (!ft_strncmp(oper, "rrb\n", str_len))
		rrb(b);
	else if (!ft_strncmp(oper, "rrr\n", str_len))
		rrr(a, b);
	else
		return (-1);
	return (0);
}

t_list	*read_inst(void)
{
	char	*oper;
	t_list	*curr;
	t_list	*opers;

	opers = malloc(sizeof(t_list));
	if (!opers)
		return (0);
	curr = opers;
	while (1)
	{
		oper = get_next_line(0);
		if (!oper)
			break ;
		curr->content = oper;
		curr->next = malloc(sizeof(t_list));
		curr = curr->next;
		if (!curr)
		{
			ft_lstclear(&opers, free);
			return (0);
		}
	}
	curr->next = NULL;
	return (opers);
}
