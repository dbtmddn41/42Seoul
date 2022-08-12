/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:23:46 by slyu              #+#    #+#             */
/*   Updated: 2022/08/09 23:23:49 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;
	int		i;

	i = 1;
	while (i < argc)
	{
		//무결성 검증
		dqadd_back(&a, ft_atoi(argv[i]));
	}
	calc_pattern(i);
}