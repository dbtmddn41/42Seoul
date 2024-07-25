/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchoi <bchoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:24:19 by bchoi             #+#    #+#             */
/*   Updated: 2021/09/26 23:24:56 by bchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h" 

int	check_jarisu(unsigned int num)
{
	int	i;

	i = 1;
	while (num / 1000 > 0)
	{
		i *= 1000;
		num /= 1000;
	}
	return (i);
}

void	process(char *num_arr, int *index, unsigned int num, int i)
{
	int	temp;

	temp = num;
	if (num >= 100)
	{
		process_2(num_arr, index, num, 100);
		num %= 100;
	}
	if (num >= 20)
	{
		process_2(num_arr, index, num, 20);
		num %= 10;
		if (num > 0)
			process_2(num_arr, index, num, 1);
	}
	else if (num >= 10)
		process_2(num_arr, index, num, 10);
	else if (num > 0)
		process_2(num_arr, index, num, 1);
	if (i == 1 || temp == 0)
		return ;
	process_jarisu(num_arr, index, i);
}

void	process_jarisu(char *num_arr, int *index, int i)
{
	num_arr[(*index)++] = '1';
	while (i >= 10)
	{
		num_arr[(*index)++] = '0';
		i /= 10;
	}
	num_arr[(*index)++] = '/';
}

void	process_2(char *num_arr, int *index, unsigned int num, int j)
{
	if (j == 100)
	{
		num_arr[(*index)++] = num / 100 + '0';
		num_arr[(*index)++] = '/';
		num_arr[(*index)++] = '1';
		num_arr[(*index)++] = '0';
		num_arr[(*index)++] = '0';
	}
	if (j == 20)
	{
		num_arr[(*index)++] = num / 10 + '0';
		num_arr[(*index)++] = '0';
	}
	if (j == 10)
	{
		num_arr[(*index)++] = '1';
		num_arr[(*index)++] = num % 10 + '0';
	}
	if (j == 1)
		num_arr[(*index)++] = num + '0';
	num_arr[(*index)++] = '/';
}

char	*make_arr(unsigned int num)
{
	unsigned int	temp;
	int				i;
	char			*num_arr;
	int				index;

	num_arr = malloc(60);
	if (!num_arr)
		return (0);
	i = check_jarisu(num);
	index = 0;
	if (num == 0)
	{
		num_arr[index++] = '0';
		num_arr[index++] = '/';
	}
	while (i > 0)
	{
		temp = (num / i) % 1000;
		process(num_arr, &index, temp, i);
		i /= 1000;
	}
	num_arr[index] = '\0';
	return (num_arr);
}
