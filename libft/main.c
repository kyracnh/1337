#include "libft.h"
#include <string.h>

int main()
{
	char *s1 = "hello man!";

	printf("%s\n", ft_strchr(s1, ' '));
	printf("%s\n", strchr(s1, ' '));
}
