/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:41:02 by slyu              #+#    #+#             */
/*   Updated: 2021/09/17 01:09:52 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	put_addr(unsigned long addr_addr, int i);
void	put_str(char *addr, unsigned int size);
void	put_num(unsigned char n);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*char_addr;

	i = 0;
	char_addr = addr;
	while (i < size)
	{
		if (i % 0x10 == 0)
		{
			put_addr(unsigned long(char_addr + i), 8);
			write(1, ": ", 2);
		}
		put_num(*(char_addr + i));
		if (i % 2)
			write(1, " ", 1);
		if (i % 0x10 == 15)
			put_str(char_addr + i - 15, 16);
		i++;
	}
	write(1, "    ", 4);
	put_str(char_addr + i - (size % 0x10) + 1, size % 0x10);
	return (addr);
}

void	put_addr(unsigned long addr, int i)
{
	if (i == 0)
		return ;
	put_addr(addr / 0x100, i - 1);
	put_num(addr % 0x100);
}

void	put_num(unsigned char n)
{
	char	first;
	char	second;

	first = n / 0x10 + 0x30;
	second = n % 0x10 + 0x30;
	if (first > '9')
		first += 0x27;
	if (second > '9')
		second += 0x27;
	write(1, &first, 1);
	write(1, &second, 1);
}

void	put_str(char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (*(addr + i) >= ' ' && *(addr + i) <= '~')
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}
