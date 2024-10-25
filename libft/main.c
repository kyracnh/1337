#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    char dest[10];
	char src[15] = "Hello Ahmed!";

	ft_memcpy(dest, src, 8);

	printf("%s\n", dest);

    return 0;
}