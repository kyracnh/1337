#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t len)
{
    unsigned    char *d;
    const   unsigned char *s;
    size_t  i;
    
    if (!dest && !src)
        return (NULL);
    
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;

    i = 0;
    if (d > s)
    {
        while (len--)
            d[len] = s[len];
    }
    else{
        while (i < len)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}
