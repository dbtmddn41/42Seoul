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
	i = 0;
	while (i < argc - 1 || (argc == 2 && args[i] != NULL))
	{
		check_push_arg(&a, args[i], ft_atoi2(args[i]));
		i++;
	}
	opers = read_inst(opers);
	if (!opers)
	{
		delete_dq(&a);
		delete_dq(&b);
		ft_lstclear(&opers, free);
		error_handler();
	}
	operate(&a, &b, opers);
	delete_dq(&a);
	delete_dq(&b);
	ft_lstclear(&opers, free);
}

void	operate(t_deque *a, t_deque *b, t_list *opers)
{
	int	res;

	while (opers != NULL)
	{
		res = execute(a, b, opers->content);
		if (res == -1)
		{
			delete_dq(a);
			delete_dq(b);
			ft_lstclear(&opers, free);
			error_handler();
		}
		opers = opers->next;
	}
	if (is_sorted(a) && is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	execute(t_deque *a, t_deque *b, char *oper)
{
	unsigned int	str_len;

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
	else if (!ft_strncmp(oper, "ra\n", str_len))
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

t_list	*read_inst(t_list *opers)
{
	char	*oper;
	t_list	*curr;

	opers = malloc(sizeof(t_list));
	if (!opers)
		return (0);
	oper = get_next_line(0);
	opers->content = oper;
	curr = opers;
	while (oper != NULL)
	{
		if (oper[0] == '\0')
		{
			curr->next = NULL;
			return (opers);
		}
		curr->next = malloc(sizeof(t_list));
		if (!curr->next)
			break ;
		curr = curr->next;
		curr->content = oper;
		oper = get_next_line(0);
	}
	return (0);
}