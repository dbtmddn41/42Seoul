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

typedef struct	s_deque_node
{
	int					data;
	struct s_deque_node	*prev;
	struct s_deque_node	*next;
}t_dnode;

typedef struct	s_deque
{
	t_dnode	*front;
	t_dnode	*rear;
}t_deque;

t_dnode	*create_node(int data, t_dnode *prev, t_dnode *next);
int		dqadd_front(t_deque *deque, int data);
int		dqadd_back(t_deque *deque, int data);
int		dqdel_front(t_deque *deque);
int		dqdel_back(t_deque *deque);

#endif