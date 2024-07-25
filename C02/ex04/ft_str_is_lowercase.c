/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:10:44 by slyu              #+#    #+#             */
/*   Updated: 2021/09/17 00:50:24 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	check;

	check = 1;
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
			check = 0;
		str++;
	}
	return (check);
}
