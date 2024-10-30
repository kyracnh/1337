#include "libft.h"
#include <fcntl.h>

int main()
{
	int fd = open("klose.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    ft_putstr_fd("hola man pppppp", fd);
    close(fd);

	return 0;
}