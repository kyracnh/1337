/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:57:03 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/01 20:57:59 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*cur;

	cur = *lst;
	if (lst && del)
	{
		while (cur)
		{
			temp = cur->next;
			del(cur->content);
			free(cur);
			cur = temp;
		}
		*lst = NULL;
	}
}
