/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:24:12 by slyu              #+#    #+#             */
/*   Updated: 2022/08/09 23:24:13 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

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

void	check_push_arg(t_deque *a, char *arg, int num);
void	push_swap(t_deque *a, t_deque *b, int n);
int		is_sorted(t_deque *dq);

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

int		ft_abs(int a);
int		log_int(int n, int x);
int		ft_pow(int n, int x);
void	ft_swap(void **a, void **b);
int		ft_atoi2(const char *str);

int		**calc_pattern(int n, int steps);
int		pattern_process(int **dir, int steps);
void	delete_all(void **to_del);
void	dp_pattern(int **dir, int i, int tri_num);

void	devide(t_deque *to_from[2], int **pattern, int n, int steps);
int		calc_small(int **pattern, int steps);

void	small_cases(t_deque *a, t_deque *b, int n, int up);
void	small_case3(t_deque *a, int up);
void	small_case456(t_deque *a, t_deque *b, int n);

int		calc_small2(int **pattern, int steps);
void	cases(t_deque *to, t_deque *from, char to_a, int pat);
void	case2(t_deque *to, t_deque *from, char to_a, int up);
void	case3(t_deque *to, t_deque *from, char to_a, int up);
void	case4(t_deque *to, t_deque *from, char to_a, int up);
void	case5(t_deque *to, t_deque *from, char to_a, int up);
void	case6(t_deque *to, t_deque *from, char to_a, int up);

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
void	swap(t_deque *to, char for_a);
void	push(t_deque *to, t_deque *from, char to_a);
void	rotate(t_deque *to, char for_a);
void	reverse_rotate(t_deque *to, char for_a);
void	swap_below(t_deque *to, char to_a);
void	store_oper(char *op);
void	print_oper(int op_n, char *opers[]);

void	three2one(t_deque *to_from[2], char to_a, int up, int limit[3]);
int		get_m(int data[3], int limit[3], int up);
void	merge(t_deque *to_from[2], int **pattern, char to_a, int step);
void	move(t_deque *(*to_from[2]), int **pattern, char *to_a, int step);

void	error_handler(void);

#endif