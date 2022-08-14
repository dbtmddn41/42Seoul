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

void	push_swap(t_deque *a, t_deque *b, int n);
void	print_deque(t_deque *d);		//제거!

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

int		ft_abs(int a);
int		log_int(int n, int x);
int		ft_pow(int n, int x);
void	ft_swap(void **a, void **b);

int		**calc_pattern(int n, int steps);
int		pattern_process(int **dir, int steps);
void	delete_all(int **to_del);

void	devide(t_deque *a, t_deque *b, int **pattern, int n);
void	devide_process(t_deque *to, t_deque *from, int **pattern, int steps);
int		calc_small(int **pattern, int steps);
int		calc_small2(int **pattern, int steps);
void	cases(t_deque *to, t_deque *from, char to_a, int pat);
void	case2(t_deque *to, t_deque *from, char to_a, int up);
void	case3(t_deque *to, t_deque *from, char to_a, int up);
void	case4(t_deque *to, t_deque *from, char to_a, int up);
void	case5(t_deque *to, t_deque *from, char to_a, int up);

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

void	three2one(t_deque *to_from[2], char to_a, int up, int limit[3]);
int		get_m(int data[3], int limit[3], int up);	
#endif