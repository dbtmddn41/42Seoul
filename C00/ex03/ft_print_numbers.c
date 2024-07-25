/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:51:01 by slyu              #+#    #+#             */
/*   Updated: 2021/09/12 13:22:26 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	num;
	int		i;

	num = '0';
	i = 0;
	while (i < 10)
	{
		write(1, &num, 1);
		i++;
		num++;
	}
}
