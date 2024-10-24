#include "libft.h"
#include <string.h>

int main()
{
	char *s1 = "hi! if you use this app, you can say : hello man! okay ?";
	char *s2 = "hello man!";

	
	printf("%s\n", ft_strnstr(s1, s2, 20));
}
