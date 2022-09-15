/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 04:41:47 by slyu              #+#    #+#             */
/*   Updated: 2022/09/01 04:41:48 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char *argv[])
{
	t_mlx_data	mlx_data;

	if (check_arg(argc, argv, &mlx_data) == -1)
		arg_error();
	fractol(&mlx_data);
	exit(0);
}

int	check_arg(int argc, char *argv[], t_mlx_data *mlx_data)
{
	if (argc < 2)
		return (-1);
	if (!ft_strncmp(argv[1], "m", ft_strlen(argv[1])))
	{
		if (argc != 2)
			return (-1);
		mlx_data->fractal_type = MANDELBROT;
	}
	else if (!ft_strncmp(argv[1], "j", ft_strlen(argv[1])))
	{
		if (argc != 4)
			return (-1);
		mlx_data->fractal_type = JULIA;
		mlx_data->pixel_num.constant.re = ft_atof(argv[2]);
		mlx_data->pixel_num.constant.im = ft_atof(argv[3]);
	}
	else if (!ft_strncmp(argv[1], "n", ft_strlen(argv[1])))
	{
		if (argc < 3)
			return (-1);
		return (newton(argc, argv, mlx_data));
	}
	else
		return (-1);
	return (0);
}

int	newton(int argc, char *argv[], t_mlx_data *mlx_data)
{
	int	degree;
	int	i;

	mlx_data->fractal_type = NEWTON;
	degree = ft_atoi(argv[2]);
	if (argc - 3 != degree * 2)
		return (-1);
	mlx_data->newton = malloc(sizeof(t_newton));
	errcheck(errno);
	mlx_data->newton->degree = degree;
	mlx_data->newton->sol = malloc(degree * sizeof(t_complex));
	errcheck(errno);
	i = -1;
	while (++i < degree * 2)
	{
		if (i % 2 == 0)
			mlx_data->newton->sol[i / 2].re = ft_atof(argv[i + 3]);
		else
			mlx_data->newton->sol[i / 2].im = ft_atof(argv[i + 3]);
	}
	return (0);
}

void	fractol(t_mlx_data *mlx_data)
{
	int			pix_start[2];
	int			pix_end[2];

	init_(mlx_data);
	set_default_pix_se(pix_start, pix_end);
	make_image(mlx_data, pix_start, pix_end);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
		mlx_data->imgdata.img, 0, 0);
	mlx_mouse_hook(mlx_data->win, mouse_hook, mlx_data);
	mlx_key_hook(mlx_data->win, key_hook, mlx_data);
	mlx_hook(mlx_data->win, X_EVENT_KEY_EXIT, 0, close_exit, NULL);
	mlx_loop(mlx_data->mlx);
}

void	init_(t_mlx_data *mlx_data)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	mlx_data->mlx = mlx_init();
	null_check(mlx_data->mlx);
	mlx_data->win = mlx_new_window(mlx_data->mlx, SIZE_X, SIZE_Y, "fractol");
	null_check(mlx_data->win);
	mlx_data->imgdata.img = mlx_new_image(mlx_data->mlx, SIZE_X, SIZE_Y);
	null_check(mlx_data->imgdata.img);
	mlx_data->imgdata.addr = mlx_get_data_addr(mlx_data->imgdata.img,
			&(mlx_data->imgdata.bits_per_pixel),
			&(mlx_data->imgdata.line_length),
			&(mlx_data->imgdata.endian));
	null_check(mlx_data->imgdata.addr);
	mlx_data->pixel_num.n_start.re = INI_START_X;
	mlx_data->pixel_num.n_start.im = INI_START_Y;
	mlx_data->pixel_num.space.re = (INI_WIDTH / SIZE_X);
	mlx_data->pixel_num.space.im = (INI_HIGHT / SIZE_Y);
	if (mlx_data->fractal_type != NEWTON)
		mlx_data->newton = NULL;
}
