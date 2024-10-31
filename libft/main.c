#include "libft.h"
#include <fcntl.h>

int main()
{
	int data = 42;
    t_list *new_node = ft_lstnew(&data);

    if (new_node)
        printf("Node content: %d\n", *(int *)new_node->content);
    else
        printf("Failed to create new node.\n");

    // Free the node after use to avoid memory leaks
    free(new_node);

    return 0;
}