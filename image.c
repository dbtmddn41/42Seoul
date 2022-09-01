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

	start[0] = mlx_data->complex_num.num_start[0];
	start[1] = mlx_data->complex_num.num_start[1];
	space[0] = mlx_data->complex_num.space[0];
	space[1] = mlx_data->complex_num.space[1];
	res = 0;
	i = pix_start[1];
	while (i < pix_end[1])
	{
		j = pix_start[0];
		while (j < pix_end[0])
		{
			if (mlx_data->fractal_type == MANDELBROT)
				res = is_bounded(0, 0, start[0] + j * space[0], start[1] - i * space[1]);
			else if (mlx_data->fractal_type == JULIA)
				res = is_bounded(start[0] + j * space[0], start[1] - i * space[1], mlx_data->complex_num.constant[0], mlx_data->complex_num.constant[1]);
			my_mlx_pixel_put(mlx_data, j, i, get_color(res, 1));
			j++;
		}
		i++;
	}
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
	}
	else
	{
		color = bw_color(iters);
	}
	return (color);
}

int	bw_color(int iters)
{
	int		red;
	int		green;
	int		blue;
	int		total;

	total = floor(iters * ((255.0 * 3) / MAXITER));
	red = total / 3 + total % 3 * 3 / 2 % 2;
	green = total / 3 + total % 3 / 2;
	blue = total / 3;
	return (red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->img_data.addr + (y * mlx_data->img_data.line_length + x * (mlx_data->img_data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}