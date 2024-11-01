#include "libft.h"
#include <fcntl.h>

// Function to double the content of a node
void double_value(void *content) {
    int *num = (int *)content;
    *num *= 2;
}

// Function to print the content of a node
void print_value(void *content) {
    int *num = (int *)content;
    printf("%d ", *num);
}

// Function to count even numbers (by modifying a global variable)
int even_count = 0;
void count_even(void *content) {
    int *num = (int *)content;
    if (*num % 2 == 0) {
        even_count++;
    }
}

int main()
{
	// Create list nodes with integer values
    t_list *head = ft_lstnew(malloc(sizeof(int)));
    t_list *node2 = ft_lstnew(malloc(sizeof(int)));
    t_list *node3 = ft_lstnew(malloc(sizeof(int)));
    t_list *node4 = ft_lstnew(malloc(sizeof(int)));

    if (!head || !node2 || !node3 || !node4) {
        perror("Memory allocation failed");
        return (EXIT_FAILURE);
    }

    // Assign integer values
    *(int *)(head->content) = 1;
    *(int *)(node2->content) = 3;
    *(int *)(node3->content) = 5;
    *(int *)(node4->content) = 7;

    // Connect nodes to form the list
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);
    ft_lstadd_back(&head, node4);

    // Step 1: Double each value in the list
    ft_lstiter(head, double_value);

    // Step 2: Print each doubled value in the list
    printf("Doubled values: ");
    ft_lstiter(head, print_value);
    printf("\n");

    // Step 3: Count even numbers
    ft_lstiter(head, count_even);
    printf("Number of even values: %d\n", even_count);

    // Free allocated memory
    ft_lstclear(&head, free);

    return (0);
}