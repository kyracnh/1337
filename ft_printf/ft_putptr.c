#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    unsigned long   addr;
    int c;

    addr = (unsigned long)ptr;
    c = 0;

    c += ft_putchar('0');
    c += ft_putchar('x');

    if (addr == 0)
    {
        c += ft_putchar('0');
    }
    else
    {
        c += ft_puthex(addr);
    }
    return (c);
}