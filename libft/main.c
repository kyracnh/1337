#include "libft.h"
#include <fcntl.h>

int main()
{
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        return 1;  // Exit if file could not be opened
    }

    // Test 1: Positive number
    ft_putnbr_fd(164651, 1);
    ft_putchar_fd('\n', 1); 

	return 0;
}