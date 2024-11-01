#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *n_list;
    t_list  *n_elem;

    n_list = NULL;
    if (lst && f && del)
    {
        while (lst)
        {
            n_elem = ft_lstnew(f(lst->content));
            if (!n_elem)
            {
                ft_lstclear(&n_list, del);
                return (NULL);
            }
            ft_lstadd_back(&n_list, n_elem);
            lst = lst->next;
        }
    }
    return (n_list);
}