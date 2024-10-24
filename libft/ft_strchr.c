#include "libft.h"

char    *ft_strchr(const char *str, int c)
{
    int i;
    char    ch;

    ch = (char) c;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
        {
            return ((char *)str + i);
        }
        i++;
    }
    return (0);
}