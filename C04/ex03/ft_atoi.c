/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:12:41 by slyu              #+#    #+#             */
/*   Updated: 2021/09/21 16:22:13 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	check_jarisu(char *str);
int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	char	buho;
	int		i;
	int		num;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == ' ' || *str == '\f')
		str++;
	buho = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			buho *= -1;
		str++;
	}
	i = check_jarisu(str);
	num = 0;
	while (i > 0)
	{
		num += (*str - 0x30) * i;
		str++;
		i /= 10;
	}
	num *= buho;
	return (num);
}

int	check_jarisu(char *str)
{
	int	i;

	i = 1;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		i *= 10;
	}
	return (i / 10);
}
