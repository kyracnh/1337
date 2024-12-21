/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:00:28 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/03 14:34:38 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_elem;
	void	*new_content;

	n_list = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			new_content = f(lst->content);
			n_elem = ft_lstnew(new_content);
			if (!n_elem)
			{
				del(new_content);
				ft_lstclear(&n_list, del);
				return (NULL);
			}
			ft_lstadd_back(&n_list, n_elem);
			lst = lst->next;
		}
	}
	return (n_list);
}
