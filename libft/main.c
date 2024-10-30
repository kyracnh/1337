#include "libft.h"
#include <fcntl.h>

int main()
{
	int c = open("kola.txt", O_WRONLY | O_CREAT, 0644);

    if (c == -1)
    {
        return (1);
    }
    ft_putchar_fd('c', c);

	return 0;
}