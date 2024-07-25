/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:58:02 by slyu              #+#    #+#             */
/*   Updated: 2022/02/16 22:58:06 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strnchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == c)
			break ;
	}
	return (i);
}

void	ft_lst_clear(t_partial **lst)
{
	t_partial	*curr;
	t_partial	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		free(curr->str);
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*lst = NULL;
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

void	capitalize(char *s)
{
	while (*s != '\0')
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 0x20;
		s++;
	}
}

void	ft_rev_tab(char *tab, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < (size / 2))
	{
		temp = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = temp;
		i++;
	}
}
