#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void *get_line(char *string)
{
	int i;

	i = 0;
	while(string[i] != '\n')
		write(1, &string[i++], 1);
}

int main(void)
{
	char *bo;
	char buffer[BUFFER_SIZE];
	int fd = open("ahmed.txt", O_RDONLY);
	if(fd != -1)
	{
		size_t numRead = read(fd, buffer, BUFFER_SIZE-1);
		while(numRead > 0)
		{
			buffer[numRead] = '\0';
			bo = malloc(sizeof(char) * strlen(buffer));
			bo = buffer;
			get_line(bo);
			numRead = read(fd, buffer, BUFFER_SIZE-1);
		}
	}
	else
	{
		printf("Sorry, can't find this file!\n");
	}
	close(fd);

	return 0;
}
