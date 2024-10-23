#include "libft.h"

int main()
{
	char dest[5];
	char *src = "Hello! libft ^^";

	printf("%zu\n", ft_strlcpy(dest, src, sizeof(dest)));
	
}
