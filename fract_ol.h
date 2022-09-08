/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:47:34 by slyu              #+#    #+#             */
/*   Updated: 2022/08/30 23:47:36 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include "libft.h"
# define MANDELBROT 0
# define JULIA 1
# define NEWTON 2
# define DBL_EPSILON 2.2204460492503131e-16

# ifdef __linux__
#  define WHEEL_UP 4
#  define WHEEL_DOWN 5
#  define L_ARROW 0xff51
#  define U_ARROW 0xff52
#  define R_ARROW 0xff53
#  define D_ARROW 0xff54
#  define LSHIFT 0xffe1
#  define ESC 0xff1b
#  define TAB 0xff09
# endif

# ifdef __APPLE__
#  define WHEEL_UP 4
#  define WHEEL_DOWN 5
#  define L_ARROW 123
#  define U_ARROW 126
#  define R_ARROW 124
#  define D_ARROW 125
#  define LSHIFT 257
#  define ESC 53
#  define TAB 48
#  define X_EVENT_KEY_EXIT 17
# endif

# define SIZE_X 720
# define SIZE_Y 400
# define ZOOM_SCALE 0.95
# define MOVE_X_SCALE (SIZE_X / 15)
# define MOVE_Y_SCALE (SIZE_Y / 15)
# define MAXITER 31
# define INI_WIDTH 4.0
# define INI_HIGHT 2.0
# define INI_X_SPACE (INI_WIDTH / SIZE_X)
# define INI_Y_SPACE (INI_HIGHT / SIZE_Y)

typedef struct s_complex_num
{
	double	num_start[2];
	double	space[2];
	double	constant[2];
}t_complex_num;

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}t_img_data;

typedef struct s_newton
{
	int		degree;
	double	*sol_re;
	double	*sol_im;
}t_newton;

typedef struct s_mlx_data {
	void			*mlx;
	void			*win;
	t_img_data		img_data;
	t_complex_num	complex_num;
	int				fractal_type;
	t_newton		*newton;
}t_mlx_data;

void	fractol(t_mlx_data *mlx_data);
int		check_arg(int argc, char *argv[], t_mlx_data *mlx_data);
int		is_bounded(double z_re, double z_im, double c_re, double c_im);
int		key_exit(int keycode, void *param);
void	init_(t_mlx_data *mlx_data);
int		key_hook(int keycode, t_mlx_data *mlx_data);
int		mouse_hook(int button, int x, int y, t_mlx_data *mlx_data);
void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color);
void	make_image(t_mlx_data *mlx_data, int pix_start[2], int pix_end[2]);
int		bw_color(int iters);
int		get_color(int iters, int mode);
void	set_default_pix_se(int *pix_start, int *pix_end);
void	cpy_known_x(t_mlx_data *mlx_data, int to_left);
void	cpy_known_y(t_mlx_data *mlx_data, int to_up);
void	move_x(int keycode, t_mlx_data *mlx_data);
void	move_y(int keycode, t_mlx_data *mlx_data);
void	pixel_cpy(t_mlx_data *mlx_data, int to[2], int from[2]);
int		newton(int argc, char *argv[], t_mlx_data *mlx_data);
int		newton_mtd(t_newton *nt, double re, double im);
void	inverse_complex(double re, double im, double *res);
int		converse_iter(t_newton *nt, int idx);
void	calc_fdfp(t_newton *nt, double re, double im, double *result);
int		check_conv(t_newton *nt, double re, double im);
int		find_closest(t_newton *nt, double re, double im);
void	errcheck(int errnum);
void	arg_error(void);
double	ft_atof(const char *str);

#endif