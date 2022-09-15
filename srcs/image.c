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
	int			color;
	t_complex	pix_num;

	color = 0;
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
			color = iterate(mlx_data, pix_num);
			my_mlx_pixel_put(mlx_data, j, i, mlx_get_color_value(mlx_data->mlx,
					color));
			j++;
		}
		i++;
	}
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
	int			res;
	t_complex	z;

	z.re = n.re;
	z.im = n.im;
	if (mlx_data->fractal_type == MANDELBROT)
	{
		z.re = 0;
		z.im = 0;
		res = is_bounded(&z, n);
	}
	else if (mlx_data->fractal_type == JULIA)
		res = is_bounded(&z, mlx_data->pixel_num.constant);
	else if (mlx_data->fractal_type == NEWTON)
		res = newton_mtd(mlx_data->newton, &z);
	else
		return (0);
	return (get_color(res, z, 1));
}
