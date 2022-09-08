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
	{
		perror("Mandelbrot set Usage: ./fract_ol m\nJULIA set Usage: ./fract_ol m <c_real> <c_imagine>\nNEWTON fractal Usage: ./fractal n <degree> <solutins>");
		return (-1);
	}
	fractol(&mlx_data);
}

int	check_arg(int argc, char *argv[], t_mlx_data *mlx_data)
{
	if (argc < 2)
		return (-1);
	if (!ft_strncmp(argv[1], "m", ft_strlen(argv[1])))
	{
		if (argc != 2)
		{
			perror("Arguement count Error\n");
			return (-1);
		}
		mlx_data->fractal_type = MANDELBROT;
	}
	else if (!ft_strncmp(argv[1], "j", ft_strlen(argv[1])))
	{
		if (argc != 4)
		{
			perror("Arguement count Error\n");
			return (-1);
		}
		mlx_data->fractal_type = JULIA;
		mlx_data->complex_num.constant[0] = atof(argv[2]);		//꼭 바꿔라
		mlx_data->complex_num.constant[1] = atof(argv[3]);
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
	// errcheck(errno);
	mlx_data->newton->degree = degree;
	mlx_data->newton->sol_re = malloc(degree * sizeof(double));	
	// errcheck(errno);
	mlx_data->newton->sol_im = malloc(degree * sizeof(double));
	// errcheck(errno);
	i = -1;
	while (++i < degree * 2)
	{
		if (i % 2 == 0)
			mlx_data->newton->sol_re[i / 2] = ft_atoi(argv[i + 3]);
		else
			mlx_data->newton->sol_im[i / 2] = ft_atoi(argv[i + 3]);
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
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img_data.img, 0, 0);
	mlx_mouse_hook(mlx_data->win, mouse_hook, mlx_data);
	mlx_key_hook(mlx_data->win, key_hook, mlx_data);
	mlx_loop(mlx_data->mlx);
}

void	init_(t_mlx_data *mlx_data)		//예외처리
{
	setvbuf(stdout, NULL, _IONBF, 0);
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, SIZE_X, SIZE_Y, "wheel");
	mlx_data->img_data.img = mlx_new_image(mlx_data->mlx, SIZE_X, SIZE_Y);
	mlx_data->img_data.addr = mlx_get_data_addr(mlx_data->img_data.img, &(mlx_data->img_data.bits_per_pixel), &(mlx_data->img_data.line_length), &(mlx_data->img_data.endian));
	mlx_data->complex_num.num_start[0] = -2.0;
	mlx_data->complex_num.num_start[1] = -1.0;
	mlx_data->complex_num.space[0] = INI_X_SPACE;
	mlx_data->complex_num.space[1] = INI_Y_SPACE;
	if (mlx_data->fractal_type != NEWTON)
		mlx_data->newton = NULL;
}