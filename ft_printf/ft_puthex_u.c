#include "ft_printf.h"

int ft_puthex_u(unsigned long n)
{
    int c;

    c = 0;
    if (n >= 16)
        c += ft_puthex_u(n / 16);
    ft_putchar("0123456789ABCDEF"[n % 16]);
    return (c + 1);
}