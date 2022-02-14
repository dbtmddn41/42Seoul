/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:27:10 by slyu              #+#    #+#             */
/*   Updated: 2022/02/01 16:27:12 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_partial
{
	char				isformat;
	char				flag[5];
	int					width[2];
	char				type;
	char				*str;
	struct s_partial	*next;
}t_partial;

typedef enum e_flag
{
	minus,
	zero,
	sharp,
	space,
	plus,
}t_flag;

int		ft_printf(const char *fstr, ...);
int		cut_str(const char *fstr, t_partial **part);
int		split_str(t_partial *part, const char *fstr);
int		format_fstr(t_partial *part, const char *fstr);
void	flag_set(int *i, t_partial *part, const char *fstr, int flag);
int		istype(char c);
int		check_flag(int *i, t_partial *part, const char *fstr);
int		write_fstr(va_list ap, t_partial *part);
int		print_c(va_list ap, t_partial *part);
int		print_s(va_list ap, t_partial *part);
int		print_p(va_list ap, t_partial *part);
int		print_d(va_list ap, t_partial *part);
int		print_u(va_list ap, t_partial *part);
int		print_x(va_list ap, t_partial *part, int islarge);
int		print_largex(va_list ap, t_partial *part);
int		print_percent(t_partial *part);
char	*x_str(va_list ap, t_partial *part);
int		ft_putstr(char *str);
void	ft_lst_clear(t_partial **lst);
int		ft_strnchr(const char *str, char c);
char	*set_cstr(int width, char zero);
void	fill_precision(int precision, char **num_str, int s_len);
int		print_cstr(char *c_str, char *str, int s_len, t_partial *part);
int		print_cstr_d(t_partial *part, char *c_str, char *num_str, int num);
char	*ft_itoa_nosign(int n);
char	*ft_itoa_unsigned(unsigned int n);
int		check_jarisu(unsigned int n);
char	*make_numstr(char *num_str, unsigned int n, int jarisu);
void	adjust_width_d(t_partial *part, int s_len, int num);
void	adjust_width_x(t_partial *part, int s_len, unsigned int num);
void	numstr2cstr(t_partial *part, char *num_str, char *c_str, int front);
void	cstr_xp(t_partial *part, char *c_str, char *num_str, int s_len);
void	put_halfbyte(unsigned char n, char *n_str);
void	make_numstr_16(unsigned int n, char *num_str);
char	*ft_itoa_x(unsigned int n);
char	*ft_itoa_p(unsigned long addr);
void	make_addrstr(unsigned long addr, char *addr_str);
void	ft_rev_tab(char *tab, int size);
void	free_all(int n, ...);
void	capitalize(char *s);
int		print_format(va_list ap, t_partial *part);
int		ft_putmem(char *s, unsigned int size);
int		precision(t_partial *part, char **s, unsigned long n);

#endif