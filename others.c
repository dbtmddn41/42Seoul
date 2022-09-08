/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:59:50 by slyu              #+#    #+#             */
/*   Updated: 2022/09/09 00:59:51 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	errcheck(int errnum)
{
	if (errnum == ENOMEM || errnum == EOVERFLOW)
	{
		perror(strerror(errnum));
		exit(-1);
	}
}

void	arg_error(void)
{
	ft_putendl_fd("Mandelbrot set Usage: ./fract_ol m", 2);
	ft_putendl_fd("JULIA set Usage: ./fract_ol m <c_real> <c_imagine>", 2);
	ft_putendl_fd("NEWTON fractal Usage: ./fractal n <degree> <solutins>", 2);
	exit(-1);
}

static int	get_integer(const char **str)
{
	int	integer;

	integer = 0;
	while (ft_isdigit(**str))
	{
		integer *= 10;
		integer += **str - '0';
		if (integer < 0)
			errcheck(EOVERFLOW);
		(*str)++;
	}
	return (integer);
}

static double	get_fraction(const char **str)
{
	int		i;
	double	fraction;

	fraction = 0.0;
	i = 10;
	while (ft_isdigit(**str))
	{
		fraction += (**str - '0') / (double)i;
		i *= 10;
		if (i  < 0)
			errcheck(EOVERFLOW);
		(*str)++;
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	int		buho;
	int		integer;
	double	fraction;

	buho = 1;
	if (*str == '-')
	{
		buho = -1;
		str++;
	}
	integer = get_integer(&str);
	fraction = 0;
	if (*str == '.')
	{
		str++;
		fraction = get_fraction(&str);
	}
	if (*str != '\0')
		arg_error();
	return (buho * (integer + fraction));
}
