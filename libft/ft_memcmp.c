#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char *block1;
	unsigned	char *block2;
	size_t	c;

	block1 = (unsigned char *)s1;
	block2 = (unsigned char *)s2;
	c = 0;
	while (c < n && (block1[i] != '\0' || block2[i] != '\0'))
	{
		if (!(block1[i] == block2[i]))
		{
			return (0);
		}
		c++;
	}
	return (block1[i] - block2[i]);
}
