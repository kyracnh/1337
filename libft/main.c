#include <stdio.h>
#include <string.h>
#include "libft.h"

int main() {
    int *p = (int*)calloc(5, sizeof(int));
    printf("%fs\n", p);

    return 0;
}
