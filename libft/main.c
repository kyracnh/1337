#include "libft.h"

int main()
{
	char *s1 = "Hello";
	char *s2 = "hello";
	size_t n = 2;

	printf("%d\n", ft_strncmp(s1, s2, sizeof(n)));
	
}
