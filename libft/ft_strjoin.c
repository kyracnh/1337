#include "libft.h"

char	*ft_strjoin(char cost *s1, char const *s2)
{
	char	*string;
	int	i;
	int	l1;
	int	l2;
	int	t_len;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	t_len = l1 + l2;
	string = (char *)malloc(t_len + 1);
	if (!string)
		return (NULL);
	i = 0;

}
