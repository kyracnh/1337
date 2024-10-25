#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    char str[20] = "Hello, World!";

	ft_memmove(str + 7, str, 5);
	printf("%s\n", str);

    return 0;
}