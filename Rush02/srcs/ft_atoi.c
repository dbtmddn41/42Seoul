/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:24:41 by slyu              #+#    #+#             */
/*   Updated: 2021/09/26 23:25:08 by bchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned int	ft_atoi(char *str)
{
	unsigned int		num;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
	{	
		if (num > 429496729 || (num == 429496729 && *str > '5'))
			return (0);
		num = num * 10 + *str - 0x30;
		str++;
	}
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == ' ' || *str == '\f')
		str++;
	if (*str != '\0')
		return (0);
	return (num);
}

int	check_zero(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	if (*str == '0')
		str++;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == ' ' || *str == '\f')
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}
