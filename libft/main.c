#include "libft.h"
#include <string.h>

int main()
{
	char *s1 = "hello man!";

	printf("%s\n", ft_strchr(s1, 'l'));
	printf("%s\n", strchr(s1, 'l'));

	printf("%s\n", ft_strrchr(s1, 'l'));
	printf("%s\n", strrchr(s1, 'l'));
}
