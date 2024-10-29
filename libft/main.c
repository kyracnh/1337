#include "libft.h"

int main()
{
	char **d = ft_split("Hello my friend how are you doing?", ' ');

	for (int i = 0; d[i] != '\0'; i++)
	{
		printf("%s\n", d[i]);
		free(d[i]);
	}
	free(d);	
	return 0;
}
