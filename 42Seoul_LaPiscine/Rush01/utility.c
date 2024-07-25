/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:33:04 by slyu              #+#    #+#             */
/*   Updated: 2021/09/18 16:39:07 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_input(int argc, char *str)
{
	int	idx;

	if (argc != 2)
		return (0);
	if (ft_strlen(str) != 31)
		return (0);
	idx = 0;
	while (str[idx] != 0)
	{
		if (idx % 2 == 0)
		{
			if (!('1' <= str[idx] && str[idx] <= '4'))
				return (0);
		}
		else
		{
			if (str[idx] != ' ')
				return (0);
		}
		idx++;
	}
	return (1);
}

void	process(int row, int col, int i, int cmd)
{
	if (cmd == 1)
	{
		boxes[i] -= 1;
		graph[row][col] = i + 1;
		row_visited[row][i] = 1;
		col_visited[col][i] = 1;
	}
	else
	{
		row_visited[row][i] = 0;
		col_visited[col][i] = 0;
		boxes[i] += 1;
	}
}
