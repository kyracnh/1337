#include "libft.h"

int main()
{
	char *s1 = "henlo";
	char *s2 = "hello";
	size_t n = 4;

	printf("%d\n", ft_strncmp(s1, s2, sizeof(n)));
	
}
