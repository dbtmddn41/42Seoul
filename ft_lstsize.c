/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:49:26 by slyu              #+#    #+#             */
/*   Updated: 2022/01/08 17:49:27 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*curr;

	if (lst == NULL)
		return (0);
	count = 1;
	curr = lst;
	while (curr -> next != NULL)
	{
		curr = curr -> next;
		count++;
	}
	return (count);
}
