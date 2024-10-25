#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    char buffer[10];

    // Fill the buffer with a non-zero character for testing
    ft_memset(buffer, 'A', sizeof(buffer));

    // Print buffer before ft_memset
    printf("Before ft_memset: ");
    for (int i = 0; i < 10; i++)
        printf("%c ", buffer[i]);
    printf("\n");

    // Apply ft_memset to the first 5 bytes
    ft_memset(buffer, 'X', 5);

    // Print buffer after ft_memset
    printf("After ft_memset: ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer[i]);
    }
    printf("\n");

    return 0;
}