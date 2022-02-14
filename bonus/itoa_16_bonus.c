/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_16_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:38:04 by slyu              #+#    #+#             */
/*   Updated: 2022/02/14 18:54:01 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_halfbyte(unsigned char n, char *n_str)
{
	char	*base;

	base = "0123456789abcdef";
	*n_str = base[n % 0x10];
}

void	make_numstr_16(unsigned int n, char *num_str)
{
	if (n == 0)
	{
		*num_str = '\0';
		return ;
	}
	make_numstr_16(n / 0x10, num_str + 1);
	put_halfbyte(n % 0x10, num_str);
}

char	*ft_itoa_x(unsigned int n)
{
	char	*num_str;

	if (n == 0)
		return (ft_strdup("0"));
	num_str = malloc(sizeof(unsigned int) * 2 + 1);
	make_numstr_16(n, num_str);
	ft_rev_tab(num_str, ft_strlen(num_str));
	return (num_str);
}

char	*ft_itoa_p(unsigned long addr)
{
	char	*addr_str;

	if (addr == 0)
		return (ft_strdup("0"));
	addr_str = malloc(sizeof(void *) * 2 + 1);
	make_addrstr(addr, addr_str);
	ft_rev_tab(addr_str, ft_strlen(addr_str));
	return (addr_str);
}

void	make_addrstr(unsigned long addr, char *addr_str)
{
	if (addr == 0)
	{
		*addr_str = '\0';
		return ;
	}
	make_addrstr(addr / 0x10, addr_str + 1);
	put_halfbyte(addr % 0x10, addr_str);
}
