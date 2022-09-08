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

	i = 0;
	while (i < MAXITER)
	{
		re -= calc_re(nt, re);
		im -= calc_im(nt, im);
		conv = check_conv(nt, re, im);
		if (conv != -1)
			return (converse_iter(nt, conv));
		i++;
	}
	return (converse_iter(nt, find_closest(nt, re, im)));
}

int	converse_iter(t_newton *nt, int idx)
{
	return (0xffffff / (double)(nt->degree) * (double)(idx + 1));
}

double	calc_re(t_newton *nt, double re)
{
	int		i;
	double	res;

	res = 0;
	i = 0;
	while (i < nt->degree)
	{
		res += re - nt->sol_re[i];
		i++;
	}
	return (res);
}

double	calc_im(t_newton *nt, double im)
{
	int		i;
	double	res;

	res = 0;
	i = 0;
	while (i < nt->degree)
	{
		res += im - nt->sol_im[i];
		i++;
	}
	return (res);
}

int	check_conv(t_newton *nt, double re, double im)
{
	int	i;

	i = 0;
	while (i < nt->degree)
	{
		if (fabs(nt->sol_re[i] - re) < DBL_EPSILON && fabs(nt->sol_im[i] - im) < DBL_EPSILON)
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