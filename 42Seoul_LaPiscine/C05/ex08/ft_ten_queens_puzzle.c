/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:21:01 by slyu              #+#    #+#             */
/*   Updated: 2021/09/26 05:08:25 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	make_pattern(unsigned char row);

int		g_count;
char	g_board[10][10];
char	g_col[10];
char	g_pattern[10];

int	ft_ten_queens_puzzle(void)
{
	make_pattern(0);
	return (g_count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	process(unsigned char row, unsigned char i, int cmd)
{
	char	j;

	g_col[i] += cmd;
	j = 0;
	while (row + j < 10 && i + j < 10)
	{
		g_board[row + j][i + j] += cmd;
		j++;
	}
	j = 0;
	while (row + j < 10 && i - j >= 0)
	{
		g_board[row + j][i - j] += cmd;
		j++;
	}
}

void	make_pattern(unsigned char row)
{
	unsigned char	i;

	if (row > 9)
	{
		write(1, &g_pattern, 10);
		write(1, "\n", 1);
		g_count++;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (g_board[row][i] == 0 && g_col[i] == 0)
		{
			g_pattern[row] = i + '0';
			process(row, i, 1);
			make_pattern(row + 1);
			process(row, i, -1);
		}
		i++;
	}
}

int	main(void)
{
	printf("%d", ft_ten_queens_puzzle());
}
