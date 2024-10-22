#include <stdio.h>
int ft_isalnum(char c)
{
	if(!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z')))
	{
		return (0);
	}
	return (1);
}
int main()
{
	printf("%d\n", ft_isalnum('#'));
}
