/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:57:57 by slyu              #+#    #+#             */
/*   Updated: 2021/09/18 16:31:30 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cnt_col_up(int col)
{
	int	row;
	int	cnt;
	int	max;

	cnt = 1;
	max = graph[0][col];
	row = 1;
	while (row < 4)
	{
		if (graph[row][col] > max)
		{
			max = graph[row][col];
			cnt += 1;
		}
		row++;
	}
	return (cnt);
}

int	cnt_col_down(int col)
{
	int	row;
	int	cnt;
	int	max;

	count = 1;
	max = graph[3][col];
	row = 2;
	while (0 <= row)
	{
		if (graph[row][col] > max)
		{
			max = graph[row][col];
			cnt += 1;
		}
		row--;
	}
	return (cnt);
}

int	cnt_row_left(int row)
{
	int	col;
	int	cnt;
	int	max;

	cnt = 1;
	max = graph[row][0];
	col = 1;
	while (col < 4)
	{
		if (graph[row][col] > max)
		{
			max = graph[row][col];
			cnt += 1;
		}
		col++;
	}
	return (cnt);
}

int	cnt_row_right(int row)
{
	int	col;
	int	cnt;
	int	max;

	cnt = 1;
	max = graph[row][3];
	col = 2;
	while (0 <= col)
	{
		if (graph[row][col] > max)
		{
			max = graph[row][col];
			cnt += 1;
		}
		col--;
	}
	return (cnt);
}
