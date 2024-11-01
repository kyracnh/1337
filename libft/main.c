#include "libft.h"
#include <fcntl.h>

// Helper functions for testing ft_lstmap
void *increment(void *content)
{
    int *num = malloc(sizeof(int));
    if (num)
        *num = *(int *)content + 1;
    return num;
}

void del(void *content)
{
    free(content);
}

int main()
{
	// Create original list
    t_list *lst = ft_lstnew(malloc(sizeof(int)));
    *(int *)(lst->content) = 1;
    ft_lstadd_back(&lst, ft_lstnew(malloc(sizeof(int))));
    *(int *)(lst->next->content) = 2;
    ft_lstadd_back(&lst, ft_lstnew(malloc(sizeof(int))));
    *(int *)(lst->next->next->content) = 3;

    // Apply ft_lstmap to create a new list
    t_list *new_lst = ft_lstmap(lst, increment, del);

    // Print contents of the new list
    t_list *tmp = new_lst;
    printf("New list contents: ");
    while (tmp)
    {
        printf("%d ", *(int *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");

    // Clean up memory
    ft_lstclear(&lst, del);
    ft_lstclear(&new_lst, del);

    return 0;
}