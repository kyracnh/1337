#include "libft.h"

int main()
{
	char *s1 = "Hello brother, how are you doing ?";
	char *s2 = ft_strtrim(s1, "doing");
	printf("%s\n", s2);
	free(s2);
	return 0;
}
