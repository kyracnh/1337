#include "libft.h"
#include <fcntl.h>

int main()
{
	t_list *head = NULL;
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");
    t_list *node4 = ft_lstnew("good");

    ft_lstadd_front(&head, node4);
    ft_lstadd_front(&head, node3); // List: node3 -> NULL
    ft_lstadd_front(&head, node2); // List: node2 -> node3 -> NULL
    ft_lstadd_front(&head, node1); // List: node1 -> node2 -> node3 -> NULL

    t_list *last = ft_lstlast(head);
    printf("Last node content: %s\n", (char *)last->content);

    return 0;
}