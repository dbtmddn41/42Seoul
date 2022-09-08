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

int	is_bounded(double z_re, double z_im, double c_re, double c_im)
{
	double			tmp;
	unsigned int	i;

	i = 0;
	while (i < MAXITER)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		if (z_re * z_re + z_im * z_im > 4)
			break ;
		i++;
	}
	return (i);
}

double	*is_bounded2(double z_re, double z_im, double c_re, double c_im)
{
	double			tmp;
	unsigned int	i;
	double			*res;

	i = 0;
	while (i < MAXITER)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		if (z_re * z_re + z_im * z_im > (1 << 16))
			break ;
		i++;
	}
	res = malloc(sizeof(double) * 3);
	res[0] = (double)i;
	res[1] = z_re;
	res[2] = z_im;
	return (res);
}