#include "libft.h"

static int  count_n(int n)
{
    int len;

    len = 0;
    if (n <= 0)
    {
        len++;
        n *= -1;
    }
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    int len;
    char    *string;
    long i;

    len = count_n(n);
    string = (char *)malloc(sizeof(char) * (len + 1));
    i = n;
    if (!string)
        return (NULL);
    string[len] = '\0';
    if (i == 0)
        string[0] = '0';
    if (i < 0)
    {
        string[0] = '-';
        i *= -1;
    }
    while (i > 0)
    {
        string[--len] = (i % 10) + '0';
        i /= 10;
    }
    return (string);
}