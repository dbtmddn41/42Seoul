/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 03:08:52 by slyu              #+#    #+#             */
/*   Updated: 2021/09/12 13:22:50 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	neg;
	char	pos;

	neg = 'N';
	pos = 'P';
	if (n < 0)
		write(1, &neg, 1);
	else
		write(1, &pos, 1);
}
