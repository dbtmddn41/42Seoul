/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:04:50 by slyu              #+#    #+#             */
/*   Updated: 2022/09/01 22:04:51 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mouse_hook(int button, int x, int y, t_mlx_data *mlx_data)
{
	static int	zoom = 0;
	double		scale;
	int			pix_start[2];
	int			pix_end[2];

	if (button == WHEEL_UP || button == WHEEL_DOWN)
	{
		if (zoom >= __INT_MAX__ || zoom <= -__INT_MAX__ - 1)
		{
			// write(2, "No more zoom!\n", 15);
			return (-1);
		}
		scale = pow(ZOOM_SCALE, zoom);
		mlx_data->complex_num.num_start[0] += (1.0 - pow(ZOOM_SCALE, pow(-1, button == WHEEL_DOWN))) * (x) * (INI_X_SPACE * scale);
		mlx_data->complex_num.num_start[1] += (1.0 - pow(ZOOM_SCALE, pow(-1, button == WHEEL_DOWN))) * (y) * (INI_Y_SPACE * scale);
		zoom += pow(-1, button == WHEEL_DOWN);
		scale = pow(ZOOM_SCALE, zoom);
		mlx_data->complex_num.space[0] = scale * INI_X_SPACE;
		mlx_data->complex_num.space[1] = scale * INI_Y_SPACE;
		set_default_pix_se(pix_start, pix_end);
		make_image(mlx_data, pix_start, pix_end);
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img_data.img, 0, 0);
	}
	return (0);
}

int	key_exit(int keycode, void *param)
{
	(void)param;
	(void)keycode;
    exit(0);
}

void	set_default_pix_se(int *pix_start, int *pix_end)
{
	pix_start[0] = 0;
	pix_start[1] = 0;
	pix_end[0] = SIZE_X;
	pix_end[1] = SIZE_Y;
}

int	key_hook(int keycode, t_mlx_data *mlx_data)
{	
	int			pix_start[2];
	int			pix_end[2];

	if (L_ARROW == keycode || keycode == D_ARROW
		|| keycode == U_ARROW || keycode == R_ARROW)
	{
		if (keycode == L_ARROW || keycode == R_ARROW)
			move_x(keycode, mlx_data);
		else
			move_y(keycode, mlx_data);
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img_data.img, 0, 0);
	}
	else if (keycode == LSHIFT || keycode == TAB)
	{
		get_color(0, 0);
		set_default_pix_se(pix_start, pix_end);
		make_image(mlx_data, pix_start, pix_end);
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img_data.img, 0, 0);
	}
	else if (keycode == ESC)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		exit(0);
	}
	return (0);
}

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
		while (cnt < SIZE_X - MOVE_X_SCALE)
		{
			to[0] = j;
			from[0] = j + MOVE_X_SCALE * (int)pow(-1, to_left == -1);
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
		while (cnt < SIZE_Y - MOVE_Y_SCALE)
		{
			to[1] = j;
			from[1] = j + MOVE_Y_SCALE * (int)pow(-1, to_up == -1);
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
		mlx_data->complex_num.num_start[0] += MOVE_X_SCALE * mlx_data->complex_num.space[0];
		cpy_known_x(mlx_data, 1);
		pix_start[0] = SIZE_X - MOVE_X_SCALE;
		pix_end[0] = SIZE_X;
	}
	else if (keycode == L_ARROW)
	{
		mlx_data->complex_num.num_start[0] -= MOVE_X_SCALE * mlx_data->complex_num.space[0];
		cpy_known_x(mlx_data, -1);
		pix_start[0] = 0;
		pix_end[0] = MOVE_X_SCALE;
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
		mlx_data->complex_num.num_start[1] -= MOVE_Y_SCALE * mlx_data->complex_num.space[1];
		cpy_known_y(mlx_data, 1);
		pix_start[1] = 0;
		pix_end[1] = MOVE_Y_SCALE;
	}
	else if (keycode == U_ARROW)
	{
		mlx_data->complex_num.num_start[1] += MOVE_Y_SCALE * mlx_data->complex_num.space[1];
		cpy_known_y(mlx_data, -1);
		pix_start[1] = SIZE_Y - MOVE_Y_SCALE;
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

	dst = mlx_data->img_data.addr + (to[1] * mlx_data->img_data.line_length + to[0] * (mlx_data->img_data.bits_per_pixel / 8));
	src = mlx_data->img_data.addr + (from[1] * mlx_data->img_data.line_length + from[0] * (mlx_data->img_data.bits_per_pixel / 8));
	*(unsigned int*)dst = *(unsigned int*)src;
}