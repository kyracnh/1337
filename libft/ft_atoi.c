#include "libft.h"

int	ft_atoi(const char *str)
{
    int i;
    int sign;
    int r;

    i = 0;
    sign = 1;
    r = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if ((str[i] == '-' && str[i + 1] == '+') || (str[i] == '+' && str[i + 1] == '-')
            || (str[i] == '-' && str[i + 1] == '-') || (str[i] == '+' && str[i + 1] == '+'))
        {
            return (0);
        }
        else if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + (str[i] - 48);
        i++;
    }
    return (r * sign);
}