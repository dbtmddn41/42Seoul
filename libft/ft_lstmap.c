/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:22:37 by slyu              #+#    #+#             */
/*   Updated: 2022/01/09 16:39:12 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_curr;

	if (!lst || !f)
		return (0);
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (0);
	new_curr = new_lst;
	while (lst != NULL)
	{
		new_curr->content = f(lst->content);
		if (lst->next == NULL)
			break ;
		new_curr->next = (t_list *)malloc(sizeof(t_list));
		if (!(new_curr->next))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_curr = new_curr->next;
		lst = lst->next;
	}
	new_curr->next = NULL;
	return (new_lst);
}
