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

int	newton_mtd(t_newton *nt, t_complex *x)
{
	int			i;
	int			conv;
	t_complex	fdfp;

	i = 0;
	while (i < MAXITER)
	{
		fdfp = calc_fdfp(nt, x);
		x->re -= fdfp.re;
		x->im -= fdfp.im;
		conv = check_conv(nt, x);
		if (conv != -1)
			return (converse_iter(nt, conv, x));
		i++;
	}
	return (converse_iter(nt, find_closest(nt, x), x));
}

t_complex	calc_fdfp(t_newton *nt, t_complex *x)
{
	t_complex	res;
	t_complex	minusinv;
	int			i;

	i = 0;
	res.re = 0;
	res.im = 0;
	while (i < nt->degree)
	{
		minusinv = inverse_complex((t_complex)
			{x->re - nt->sol[i].re, x->im - nt->sol[i].im});
		res.re += minusinv.re;
		res.im += minusinv.im;
		i++;
	}
	return (inverse_complex(res));
}

t_complex	inverse_complex(t_complex n)
{
	double		size;
	t_complex	res;

	size = pow(pow(n.re, 2.0) + pow(n.im, 2.0), -1);
	res.re = n.re * size;
	res.im = -n.im * size;
	return (res);
}

int	check_conv(t_newton *nt, t_complex *x)
{
	int	i;

	i = 0;
	while (i < nt->degree)
	{
		if (fabs(nt->sol[i].re - x->re) < DBL_EPSILON
			&& fabs(nt->sol[i].im - x->im) < DBL_EPSILON)
			return (i);
		i++;
	}
	return (-1);
}

int	find_closest(t_newton *nt, t_complex *x)
{
	int		close_idx;
	int		i;
	double	dist;
	double	min_dist;

	min_dist = pow(nt->sol[0].re - x->re, 2) + pow(nt->sol[0].im - x->im, 2);
	close_idx = 0;
	i = 1;
	while (i < nt->degree)
	{
		dist = pow(nt->sol[i].re - x->re, 2) + pow(nt->sol[i].im - x->im, 2);
		if (dist < min_dist)
		{
			min_dist = dist;
			close_idx = i;
		}
		i++;
	}
	return (i);
}
