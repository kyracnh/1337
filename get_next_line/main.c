#include "get_next_line.h"

int main(void)
{
	int fd = open("ahmed.txt", O_RDONLY);
	if(fd == -1)
		return 1;
	
	char *line = get_next_line(fd);

	while(line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return 0;
}
