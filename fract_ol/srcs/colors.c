/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:05:45 by slyu              #+#    #+#             */
/*   Updated: 2022/09/15 16:05:46 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	get_color(int iters, t_complex n, int mode)
{
	static int	color_type = 0;
	int			color;

	if (mode == 0)
	{
		color_type = (color_type + 1) % 4;
		return (0);
	}
	if (color_type == 0)
		color = get_smoothcolor(iters, n,
				(t_palette){4, {0x2FF3E0, 0xF8D210, 0xFA26A0, 0xF51720}});
	else if (color_type == 1)
		color = (int)(0xffffff / MAXITER * (double)iters);
	else if (color_type == 2)
		color = get_smoothcolor(iters, n, (t_palette)
			{5, {0x8a00d4, 0xe3e3e3, 0xd527b7, 0xf782c2, 0xf9c46b}});
	else
		color = get_smoothcolor(iters, n, (t_palette){2, {0x0, 0xffffff}});
	return (color);
}

int	get_smoothcolor(int iters, t_complex n, t_palette palette)
{
	double	nu;
	double	sm_iter;
	double	idx;
	int		color[2];
	double	rate;

	if (iters < MAXITER)
	{
		nu = log2(log2(n.re * n.re + n.im * n.im) / 2.0);
		sm_iter = iters + 1 - nu;
	}
	else
		sm_iter = iters;
	if (sm_iter < 0)
		sm_iter = 0;
	idx = (sm_iter / MAXITER);
	rate = fmod(sm_iter / MAXITER, 1.0 / (palette.color_num - 1))
		* (palette.color_num - 1);
	color[0] = palette.colors[(int)floor(idx * (palette.color_num - 1))];
	color[1] = palette.colors[((int)floor(idx * (palette.color_num - 1)) + 1)];
	return (linear_interpolate(color[0], color[1], (int)(rate + 1) - rate));
}

int	linear_interpolate(int color1, int color2, double rate)
{
	int	rgb[3];
	int	i;

	i = 16;
	while (i >= 0)
	{
		rgb[i / 8] = (color1 >> i & 0xff) * rate
			+ (color2 >> i & 0xff) * (1 - rate);
		i -= 8;
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
