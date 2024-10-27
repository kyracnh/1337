#include "libft.h"

int main()
{
    char *origin = "Hello Ahmed!";
    char *copy = ft_strdup(origin);

    if (copy)
    {
        printf("Original : %s\n", origin);
        printf("Copy : %s\n", copy);
        free(copy);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
