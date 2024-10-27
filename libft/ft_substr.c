#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*string;
	int	i;
	int	j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i == start)
			length = ft_strlen(s) - i;
		string = (char *)malloc(sizeof(char) * len);
		j = 0;
		while (s[j] != length)
			string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
