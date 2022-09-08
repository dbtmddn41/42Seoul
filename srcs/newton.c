/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@tudent.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:59 by slyu              #+#    #+#             */
/*   Updated: 2022/09/08 19:38:01 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	newton_mtd(t_newton *nt, double re, double im)
{
	int		i;
	int		conv;
	double	fdfp[2];

	i = 0;
	while (i < MAXITER)
	{
		calc_fdfp(nt, re, im, fdfp);
		re -= fdfp[0];
		im -= fdfp[1];
		conv = check_conv(nt, re, im);
		if (conv != -1)
			return (converse_iter(nt, conv));
		i++;
	}
	return (converse_iter(nt, find_closest(nt, re, im)));
}

void	calc_fdfp(t_newton *nt, double re, double im, double *result)
{
	double	res[2];
	int		i;

	i = 0;
	result[0] = 0;
	result[1] = 0;
	while (i < nt->degree)
	{
		inverse_complex(re - nt->sol_re[i], im - nt->sol_im[i], res);
		result[0] += res[0];
		result[1] += res[1];
		i++;
	}
	inverse_complex(result[0], result[1], result);
	return ;
}

void	inverse_complex(double re, double im, double *res)
{
	double	size;

	size = pow(pow(re, 2.0) + pow(im, 2.0), -1);
	res[0] = re * size;
	res[1] = -im * size;
	return ;
}

int	check_conv(t_newton *nt, double re, double im)
{
	int	i;

	i = 0;
	while (i < nt->degree)
	{
		if (fabs(nt->sol_re[i] - re) < DBL_EPSILON && fabs(nt->sol_im[i] - im)
			< DBL_EPSILON)
			return (i);
		i++;
	}
	return (-1);
}

int	find_closest(t_newton *nt, double re, double im)
{
	int		close_idx;
	int		i;
	double	dist;
	double	min_dist;

	min_dist = pow(nt->sol_re[0] - re, 2) + pow(nt->sol_im[0] - im, 2);
	close_idx = 0;
	i = 1;
	while (i < nt->degree)
	{
		dist = pow(nt->sol_re[i] - re, 2) + pow(nt->sol_im[i] - im, 2);
		if (dist < min_dist)
		{
			min_dist = dist;
			close_idx = i;
		}
		i++;
	}
	return (i);
}
