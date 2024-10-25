#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    char arr[] = "Hello, World!";
    
    // Look for character 'W' within the first 12 bytes
    char *result = (char *)ft_memchr(arr, 'W', 12);

    if (result != NULL) {
        printf("Found 'W' at position: %ld\n", result - arr);
    } else {
        printf("'W' not found within the first 12 bytes.\n");
    }

    return 0;
}