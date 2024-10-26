#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    int *p;

    p = (int *)ft_calloc(5, sizeof(int));

    if (!p)
    {
        printf("l3ya9a hadi!\n");
        return 1;
    }

    for (size_t i = 0; i < 5; i++)
    {
        if (p[i] != 0)
        {
            printf("Test madazch : %zu is not zero\n", i);
            free(p);
            return 1;
        }
        printf("Kolchi daz mzyan ^^\n");

        free(p);
        return 0;
        
    }
    
    

    return 0;
}
