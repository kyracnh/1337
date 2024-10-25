#include "libft.h"

void    *ft_memset(void *buf, int c, size_t len)
{
    unsigned    char *block;
    size_t  i;

    block = (unsigned char *)buf;
    i = 0;
    while (i < len)
    {
        block[i] = (unsigned char)c;
        i++;
    }
    return (block);
}