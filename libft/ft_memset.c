#include "libft.h"

void    *ft_memset(void *buf, int c, size_t len)
{
    unsigned    char *p;
    size_t  i;

    p = (unsigned char *)buf;
    i = 0;
    while (i < len)
    {
        p[i] = (unsigned char)c;
        i++;
    }
    return (p);
}