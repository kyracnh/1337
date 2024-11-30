#include "get_next_line.h"

int main(void)
{
	int fd = open("ahmed.txt", O_RDONLY);
	if(fd == -1)
		return 1;
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return 0;
}
