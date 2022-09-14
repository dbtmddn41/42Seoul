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
	int			i;
	int			j;
	int			res;
	t_complex	pix_num;

	res = 0;
	i = pix_start[1];
	while (i < pix_end[1])
	{
		j = pix_start[0];
		while (j < pix_end[0])
		{
			pix_num.re = mlx_data->pixel_num.n_start.re
				+ j * mlx_data->pixel_num.space.re;
			pix_num.im = mlx_data->pixel_num.n_start.im
				+ i * mlx_data->pixel_num.space.im;
			res = iterate(mlx_data, pix_num);
			my_mlx_pixel_put(mlx_data, j, i, mlx_get_color_value(mlx_data->mlx,
					get_color(res, 1)));
			j++;
		}
		i++;
	}
}

int	bw_color(double iters)
{
	double	v;
	int		rgb;

	v = pow(pow(iters / MAXITER, 1.0) * 0xff, 1.5);
	v = fmod(v, 0xff);
	rgb = floor(iters / MAXITER * 0xff);
	return (rgb << 16 | rgb << 8 | rgb);
}

int	get_color(double iters, int mode)
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
		color = ~(int)(0xffffff / MAXITER * (double)iters);
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

int	iterate(t_mlx_data *mlx_data, t_complex n)
{
	int	res;

	if (mlx_data->fractal_type == MANDELBROT)
		res = is_bounded(&(t_complex){0, 0}, &n);
	else if (mlx_data->fractal_type == JULIA)
		res = is_bounded(&n, &(mlx_data->pixel_num.constant));
	else if (mlx_data->fractal_type == NEWTON)
		res = newton_mtd(mlx_data->newton, n.im, n.re);
	else
		res = 0;
	return (res);
}
