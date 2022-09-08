/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:03:12 by slyu              #+#    #+#             */
/*   Updated: 2022/09/01 22:03:13 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	make_image(t_mlx_data *mlx_data, int pix_start[2], int pix_end[2])
{
	int		i;
	int		j;
	int		res;
	double	start[2];
	double	space[2];

	start[0] = mlx_data->complex_num.n_start[0];
	start[1] = mlx_data->complex_num.n_start[1];
	space[0] = mlx_data->complex_num.space[0];
	space[1] = mlx_data->complex_num.space[1];
	res = 0;
	i = pix_start[1];
	while (i < pix_end[1])
	{
		j = pix_start[0];
		while (j < pix_end[0])
		{
			res = iterate(mlx_data, start[0] + j * space[0],
					start[1] + i * space[1]);
			my_mlx_pixel_put(mlx_data, j, i, mlx_get_color_value(mlx_data->mlx,
					get_color(res, 1)));
			j++;
		}
		i++;
	}
}

int	bw_color(int iters)
{
	double	v;

	v = pow((double)iters / MAXITER * 0xff, 1.5);
	v = fmod(v, 0xff);
	return ((int)v << 16 | (int)v << 8 | (int)v);
}

int	get_color(int iters, int mode)
{
	static int	color_type = 0;
	int			color;

	if (mode == 0)
	{
		color_type = (color_type + 1) % 3;
		return (0);
	}
	if (color_type == 0)
	{
		color = (int)(0xffffff / (double)MAXITER * (double)iters);
	}
	else if (color_type == 1)
	{
		color = ~(int)(0xffffff / (double)MAXITER * (double)iters);
		color &= 0x00ffffff;
	}
	else
	{
		color = bw_color(iters);
	}
	return (color);
}

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->imgdata.addr + ((SIZE_Y - 1 - y)
			* mlx_data->imgdata.line_length + x
			* (mlx_data->imgdata.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	iterate(t_mlx_data *mlx_data, double re, double im)
{
	int	res;

	if (mlx_data->fractal_type == MANDELBROT)
		res = is_bounded(0, 0, re, im);
	else if (mlx_data->fractal_type == JULIA)
		res = is_bounded(re, im, mlx_data->complex_num.constant[0],
				mlx_data->complex_num.constant[1]);
	else if (mlx_data->fractal_type == NEWTON)
		res = newton_mtd(mlx_data->newton, im, re);
	else
		res = 0;
	return (res);
}
