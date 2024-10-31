#include "libft.h"
#include <fcntl.h>

int main()
{
	t_list *head = NULL;
    t_list *node1 = ft_lstnew("Node 1");

    ft_lstadd_front(&head, node1);

    int size = ft_lstsize(head);  // Call the function to get the list size
    printf("List size: %d\n", size);  // Expected output: List size: 3

    return 0;
}