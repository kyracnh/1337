#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    char ar1[] = "Hello, World!";
    char ar2[] = "Hello, 6 World!";

    printf("%d\n", ft_memcmp(ar1, ar2, 8));
    printf("%d\n", memcmp(ar1, ar2, 8));

    return 0;
}
