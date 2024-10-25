#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *src;
    unsigned    char byte;
    size_t  i;

    src = (unsigned char *)s;
    byte = (unsigned char)c;
    i = 0;

    while (i < n)
    {
        if (src[i] == byte)
        {
            return ((char *)s + i);
        }
        i++;
    }
    return (NULL);
}