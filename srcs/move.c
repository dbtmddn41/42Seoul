/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:35:13 by slyu              #+#    #+#             */
/*   Updated: 2022/09/09 02:35:14 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	cpy_known_x(t_mlx_data *mlx_data, int to_left)
{
	int	i;
	int	j;
	int	cnt;
	int	to[2];
	int	from[2];

	i = 0;
	while (i < SIZE_Y)
	{
		j = (SIZE_X - 1) * (to_left == -1);
		cnt = 0;
		while (cnt < SIZE_X - (SIZE_X / MOVE_RATE))
		{
			to[0] = j;
			from[0] = j + (SIZE_X / MOVE_RATE) * (int)pow(-1, to_left == -1);
			to[1] = i;
			from[1] = i;
			pixel_cpy(mlx_data, to, from);
			j += to_left;
			cnt++;
		}
		i++;
	}
}

void	cpy_known_y(t_mlx_data *mlx_data, int to_up)
{
	int	i;
	int	j;
	int	cnt;
	int	to[2];
	int	from[2];

	i = 0;
	while (i < SIZE_X)
	{
		j = (SIZE_Y - 1) * (to_up == -1);
		cnt = 0;
		while (cnt < SIZE_Y - (SIZE_Y / MOVE_RATE))
		{
			to[1] = j;
			from[1] = j + (SIZE_Y / MOVE_RATE) * (int)pow(-1, to_up == -1);
			to[0] = i;
			from[0] = i;
			pixel_cpy(mlx_data, to, from);
			j += to_up;
			cnt++;
		}
		i++;
	}
}

void	move_x(int keycode, t_mlx_data *mlx_data)
{
	int	pix_start[2];
	int	pix_end[2];

	if (keycode == R_ARROW)
	{
		mlx_data->complex_num.n_start[0] += (SIZE_X / MOVE_RATE)
			* mlx_data->complex_num.space[0];
		cpy_known_x(mlx_data, 1);
		pix_start[0] = SIZE_X - (SIZE_X / MOVE_RATE);
		pix_end[0] = SIZE_X;
	}
	else if (keycode == L_ARROW)
	{
		mlx_data->complex_num.n_start[0] -= (SIZE_X / MOVE_RATE)
			* mlx_data->complex_num.space[0];
		cpy_known_x(mlx_data, -1);
		pix_start[0] = 0;
		pix_end[0] = (SIZE_X / MOVE_RATE);
	}
	pix_start[1] = 0;
	pix_end[1] = SIZE_Y;
	make_image(mlx_data, pix_start, pix_end);
}

void	move_y(int keycode, t_mlx_data *mlx_data)
{
	int	pix_start[2];
	int	pix_end[2];

	if (keycode == D_ARROW)
	{
		mlx_data->complex_num.n_start[1] -= (SIZE_Y / MOVE_RATE)
			* mlx_data->complex_num.space[1];
		cpy_known_y(mlx_data, 1);
		pix_start[1] = 0;
		pix_end[1] = (SIZE_Y / MOVE_RATE);
	}
	else if (keycode == U_ARROW)
	{
		mlx_data->complex_num.n_start[1] += (SIZE_Y / MOVE_RATE)
			* mlx_data->complex_num.space[1];
		cpy_known_y(mlx_data, -1);
		pix_start[1] = (SIZE_Y - SIZE_Y / MOVE_RATE);
		pix_end[1] = SIZE_Y;
	}
	pix_start[0] = 0;
	pix_end[0] = SIZE_X;
	make_image(mlx_data, pix_start, pix_end);
}

void	pixel_cpy(t_mlx_data *mlx_data, int to[2], int from[2])
{
	char	*src;
	char	*dst;

	dst = mlx_data->imgdata.addr + (to[1] * mlx_data->imgdata.line_length
			+ to[0] * (mlx_data->imgdata.bits_per_pixel / 8));
	src = mlx_data->imgdata.addr + (from[1] * mlx_data->imgdata.line_length
			+ from[0] * (mlx_data->imgdata.bits_per_pixel / 8));
	*(unsigned int *)dst = *(unsigned int *)src;
}
