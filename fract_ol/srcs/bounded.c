/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounded.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:41:53 by slyu              #+#    #+#             */
/*   Updated: 2022/08/30 04:41:55 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	is_bounded(t_complex *z, t_complex c)
{
	t_complex		tmp;
	unsigned int	i;

	i = 0;
	while (i < MAXITER && z->re * z->re + z->im * z->im <= 4)
	{
		tmp.re = z->re * z->re - z->im * z->im + c.re;
		tmp.im = 2 * z->re * z->im + c.im;
		if (fabs(tmp.re - z->re) < DBL_EPSILON
			&& fabs(tmp.im - z->im) < DBL_EPSILON)
			return (MAXITER);
		z->re = tmp.re;
		z->im = tmp.im;
		i++;
	}
	return (i);
}
/* 
double	iterate2(t_mlx_data *mlx_data, t_complex n)
{
	double	res;
	double	*resm;
	double	nu;

	if (mlx_data->fractal_type == MANDELBROT)
	{
		resm = is_bounded2(0, 0, n.re, n.im);
		if (resm[0] < MAXITER)
		{
			nu = log2(log(pow(resm[1], 2) + pow(resm[2], 2)) / 2.0 / log(2));
			resm[0] = resm[0] + 1 - nu;
		}
		// resm[0] = fmod(resm[0], 1);
		res = resm[0];
		free(resm);
		return (res);
	}
	else if (mlx_data->fractal_type == JULIA)
		res = is_bounded(n, mlx_data->pixel_num.constant.re,
				mlx_data->pixel_num.constant.im);
	else if (mlx_data->fractal_type == NEWTON)
		res = newton_mtd(mlx_data->newton, n.im, n.re);
	else
		res = 0;
	return (res);
}
 */