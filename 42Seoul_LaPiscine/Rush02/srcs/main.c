/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyang <eyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:01:29 by eyang             #+#    #+#             */
/*   Updated: 2021/09/26 23:41:39 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	check_argc(int argc, char **argv, char **nb, char **dictpath)
{
	if (argc == 2)
	{
		*dictpath = "numbers.dict";
		*nb = argv[1];
		return (1);
	}
	else if (argc == 3)
	{
		*dictpath = argv[1];
		*nb = argv[2];
		return (1);
	}
	return (0);
}

void	start_search(char *num_arr, char *path)
{
	int		fd;
	int		n;
	int		i;
	char	buf[1001];
	char	to_print[1001];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		return ;
	}
	else
	{
		i = 0;
		n = read(fd, buf, 1000);
	}
	if (open_dict(n, buf, num_arr, to_print) > 0)
		ft_putstr(to_print);
	else
		write(1, "Dict Error\n", 11);
	close(fd);
}

int	check_error(char *num_arr, unsigned int num)
{
	if (!num_arr || !num)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	char			*nb;
	char			*path;
	char			*num_arr;
	unsigned int	num;

	num = 1;
	num_arr = 0;
	if (!check_argc(argc, argv, &nb, &path))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (check_zero(nb))
		num_arr = make_arr(0);
	else
	{
		num = ft_atoi(nb);
		if (num)
			num_arr = make_arr(num);
	}
	if (check_error(num_arr, num))
		return (0);
	start_search(num_arr, path);
	free(num_arr);
	return (0);
}
