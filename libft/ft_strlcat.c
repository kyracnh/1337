#include "libft.h"

size_t  strlcat(char *dest, const char *src, size_t destsize)
{
    size_t  dest_len;
    size_t  src_len;
    size_t  i;

    dest_len = 0;
    while (dest_len < destsize && dest[dest_len] != '\0')
    {
        dest_len++;
    }
    
    src_len = ft_strlen(src);

    i = 0;
    while (dest[i] != '\0' && (dest_len + 1) < (destsize - 1))
    {
        dest[dest_len + i] = src[i];
        i++;
    }

    dest[dest_len+ i] = '\0';

    return (dest_len + src_len);
}
