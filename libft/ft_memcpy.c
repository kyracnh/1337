#include "libft.h"

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned    char *d;
    const unsigned char *s;
    size_t  i;

    if (dst == NULL && src == NULL)
        return (NULL);

    d = (unsigned char *)dst;
    s = (const unsigned char *)src;
    if (d == s)
        return (d);
    
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dst);
}