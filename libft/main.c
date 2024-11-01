#include "libft.h"
#include <fcntl.h>

void delete_content(void *content)
{
    free(content);
}

int main()
{
	t_list *head = ft_lstnew(strdup("Node 1"));
    ft_lstadd_back(&head, ft_lstnew(strdup("Node 2")));
    ft_lstadd_back(&head, ft_lstnew(strdup("Node 3")));

    // Clear the list and free all memory
    ft_lstclear(&head, delete_content);

    if (head == NULL)
        printf("List successfully cleared.\n");
    else
        printf("List clear failed.\n");

    return 0;
}