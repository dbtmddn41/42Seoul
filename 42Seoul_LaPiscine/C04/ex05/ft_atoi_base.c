/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:02:28 by slyu              #+#    #+#             */
/*   Updated: 2021/09/22 19:14:26 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(char *str, char *base);
int	check_jarisu(char *str, int base_num, char *base);
int	check_base(char *base);
int	make_num(char *str, int i, int base_num, char *base);

int	ft_atoi_base(char *str, char *base)
{
	char	buho;
	int	i;
	int	num;
	int	j;
	int	base_num;

    base_num = check_base(base);
    while (*str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\r' || *str == ' ' || *str == '\f')
		str++;
    buho = 1;
    while (*str == '+' || *str == '-')
    {
	if (*str == '-')
		buho *= -1;
	str++;
    }
    i = check_jarisu(str, base_num, base);
    num = make_num(str, i, base_num, base);
    num *= buho;
    return (num);
}

int	make_num(char *str, int i, int base_num, char *base)
{
	int	j;
	int	num;

	num = 0;
	j = 0;
	while (i > 0)
	{
        j = 0;
        while (*str != base[j])
            j++;
		num += j * i;
		str++;
		i /= base_num;
	}
	return (num);
}

int	check_base(char *base)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	size = 0;
	while (*(base + size) != '\0')
	{
		if (*(base + size) == '+' || *(base + size) == '-')
			return (0);
		size++;
	}
	if (size < 2)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (size);
}

int	check_jarisu(char *str, int base_num, char *base)
{
	int     i;
    int     j;
    char    check;

	i = 1;
    check = 0;
	while (*str != '\0')
	{
		j = 0;
        while (j < base_num)
        {
            if (*str == base[j])
            {
                check = 1;
                break;
            }
            j++;
        }
        if (check == 0)
            break;
		str++;
		i *= base_num;
	}
	return (i / base_num);
}

int main(void)
{
    printf("%x", ft_atoi_base(" 	+eadbeef", "0123456789abcdef"));
}
