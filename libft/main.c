#include "libft.h"
#include <fcntl.h>

void print_list(t_list *head) {
    t_list *current = head;
    while (current) {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
	t_list *head = NULL;

    // Create new nodes
    t_list *node1 = ft_lstnew("First Node");
    t_list *node2 = ft_lstnew("Second Node");
    t_list *node3 = ft_lstnew("Third Node");
    t_list *node4 = ft_lstnew("ara lakhor");

    // Add nodes to the back of the list
    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);
    ft_lstadd_back(&head, node4);

    // Print the list to verify the contents
    printf("Linked List after adding nodes to the back:\n");
    print_list(head);

    return 0;
}