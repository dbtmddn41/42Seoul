/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:35:35 by slyu              #+#    #+#             */
/*   Updated: 2021/09/30 06:07:36 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	check_base(char *base);

int	check_size(int num, int base_num)
{
	unsigned int	usn_num;
	int				size;

	if (num == 0)
		return (1);
	else if (num < 0)
		usn_num = num * (-1);
	else
		usn_num = num;
	size = 0;
	while (usn_num > 0)
	{
		usn_num /= base_num;
		size++;
	}
	return (size);
}

void	put_str(unsigned int num, char *base_to, int base_num, char **ptr_addr)
{
	if (num == 0)
		return ;
	put_str(num / base_num, base_to, base_num, ptr_addr);
	*((*ptr_addr)++) = base_to[num % base_num];
}

char	*ft_itoa_base(int num, char *base_to)
{
	unsigned int	uns_num;
	char			*ptr;
	int				base_num;
	int				size;

	base_num = check_base(base_to);
	if (!base_num)
		return (0);
	size = check_size(num, base_num);
	ptr = malloc(size + 2);
	if (!ptr)
		return (0);
	if (num < 0)
	{
		uns_num = num * (-1);
		*ptr = '-';
		ptr++;
	}
	else if (num == 0)
	{
		*ptr = base_to[0];
		*(ptr + 1) = '\0';
		return (ptr);
	}
	else
		uns_num = num;
	put_str(uns_num, base_to, base_num, &ptr);
	*ptr = '\0';
	if (num < 0)
		return (ptr - size - 1);
	return (ptr - size);
}
