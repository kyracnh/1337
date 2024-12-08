#include "ft_printf.h"

int ft_puthex(unsigned long n)
{
    int c;

    c = 0;
    if (n >= 16)
        c += ft_puthex(n / 16);
    ft_putchar("0123456789abcdef"[n % 16]);
    return (c + 1);
}