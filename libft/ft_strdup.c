#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *string;
    int i;
    int len;

    len = ft_strlen(s);
    string = (char *)malloc(len * sizeof(char) + 1);
    i = 0;
    if (!string)
        return (NULL);
    while (s[i] < len)
    {
        string[i] = s[i];
        i++;
    }
    string[i] = '\0';

    return (string);
}