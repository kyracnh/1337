#include "ft_printf.h"

int main()
{

     int i = ft_printf("hello : %i\n", 12541);
     int c = printf("hello : %i\n", 12541);

     ft_printf("i = %d\n", i);
     ft_printf("c = %d\n", c);
}