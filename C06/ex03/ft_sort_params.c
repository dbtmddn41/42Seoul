/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:51:45 by slyu              #+#    #+#             */
/*   Updated: 2021/09/27 17:36:07 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*temp;

	i = 2;
	while (i < argc)
	{
		j = i;
		while (ft_strcmp(argv[j - 1], argv[j]) > 0)
		{
			temp = argv[j - 1];
			argv[j - 1] = argv[j];
			argv[j] = temp;
			j--;
			if (j == 1)
				break ;
		}
		i++;
	}
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
	return (0);
}
