#include "libft.h"
#include <fcntl.h>

int main()
{
	int fd = open("klose.txt", O_WRONLY | O_CREAT, 0644);

    ft_putstr_fd("hola man pppppp\n", fd);
    fclose(fd);

	return 0;
}