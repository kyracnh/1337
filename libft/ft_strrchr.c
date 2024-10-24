#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    int len;

    len = ft_strlen(str);
    while (len >= 0)
    {
        if (str[len] == (char) c)
        {
            return ((char *)str + len);
        }
        if (len == 0)
        {
            break;
        }
        len--;
    }
    return (0);
    
}