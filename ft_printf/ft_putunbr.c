#include "ft_printf.h"

int ft_putunbr(unsigned int n)
{
    int c;

    c = 0;
    if (n >= 10)
        c += ft_putunbr(n / 10);
    ft_putchar(n % 10 + '0');
    return (c + 1);
}