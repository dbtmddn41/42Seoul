/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:08:03 by slyu              #+#    #+#             */
/*   Updated: 2022/01/09 19:09:08 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*temp;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		del(curr->content);
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*lst = NULL;
}
