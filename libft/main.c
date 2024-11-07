#include "libft.h"

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8};

    ft_memmove(v + 2, v, sizeof(int) * 4);
    for (size_t i = 0; i < 8; i++)
    {
        printf("v : %d\n", v[i]);
    }
    
    
}