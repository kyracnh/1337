#include "libft.h"

int main()
{
    size_t count = 5;
    size_t size = sizeof(int);
    int *arr = (int *)ft_calloc(count, size);

    if (!arr)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Check if all elements are zero-initialized
    int test_passed = 1;
    for (size_t i = 0; i < count; i++)
    {
        if (arr[i] != 0)
        {
            printf("Test failed: arr[%zu] is not zero.\n", i);
            test_passed = 0;
            break;
        }
    }

    if (test_passed)
    {
        printf("Test passed: All elements are zero-initialized.\n");
    }

    free(arr);
    return 0;
}
