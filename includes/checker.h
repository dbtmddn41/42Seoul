/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 01:12:17 by slyu              #+#    #+#             */
/*   Updated: 2022/08/19 01:12:18 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_deque_node
{
	int					data;
	struct s_deque_node	*prev;
	struct s_deque_node	*next;
}t_dnode;

typedef struct s_deque
{
	t_dnode	*front;
	t_dnode	*rear;
}t_deque;

void	dq_init(t_deque *dq);
void	delete_dq(t_deque *dq);
t_dnode	*create_node(int data, t_dnode *prev, t_dnode *next);
int		dqadd_front(t_deque *deque, int data);
int		dqadd_back(t_deque *deque, int data);
int		dqdel_front(t_deque *deque);
int		dqdel_back(t_deque *deque);
void	dqadd_front_node(t_deque *deque, t_dnode *node);
void	dqadd_back_node(t_deque *deque, t_dnode *node);
t_dnode	*dqdel_front_node(t_deque *deque);
t_dnode	*dqdel_back_node(t_deque *deque);
int		check_dupli(t_deque *dq, int num);
int		is_sorted(t_deque *dq);
int		is_empty(t_deque *dq);

t_list	*read_inst(void);
void	check_push_arg(t_deque *a, char *arg, int num);
int		execute2(t_deque *a, t_deque *b, char *oper, unsigned int str_len);
int		execute(t_deque *a, t_deque *b, char *oper);
void	operate(t_deque *a, t_deque *b, t_list *opers);
void	error_handler(void);

int		ft_atoi2(const char *str);

void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);

#endif