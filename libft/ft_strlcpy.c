#include <stddef.h>
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t len;

	while (src[len] != '\0')
		len++;

	size_t i;
	i = 0;
	while (src[i] != '\0' && i < size)
	{
		src[i] = dest[i];
		i++;
	}
	dest[i] = '\0';

	return (len);
}
