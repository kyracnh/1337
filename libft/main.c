#include "libft.h"
#include <fcntl.h>

void print_list(t_list *head)
{
    t_list *current = head;
    while (current)
    {
        printf("%s -> ", (char *)current->content);  // Cast content to char* and print
        current = current->next;
    }
    printf("NULL\n");  // End of list
}

int main()
{
	t_list *head = NULL;           // Start with an empty list (NULL)
    t_list *new_node1 = ft_lstnew("Hello");
    t_list *new_node2 = ft_lstnew("World");

    ft_lstadd_front(&head, new_node1);  // Add "Hello" to the front
    print_list(head);  // Print list: Expected output -> "Hello -> NULL"

    ft_lstadd_front(&head, new_node2);  // Add "World" to the front
    print_list(head);  // Print list: Expected output -> "World -> Hello -> NULL"

    return 0;
}