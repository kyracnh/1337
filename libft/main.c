#include "libft.h"
#include <string.h>

int main()
{
	char *s1 = "hello";
	char *s2 = "hello";
	size_t n = 5;

	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
}
