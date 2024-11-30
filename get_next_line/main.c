#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

int main(void)
{
	static char *reserve;
	char *bo;
	char *buffer;
	char *temp;
	size_t numRead;


	buffer = malloc(BUFFER_SIZE);
	if(!buffer)
	{
		free(buffer);
		return (0);
	}
	int fd = open("ahmed.txt", O_RDONLY);
	if(fd == -1)
		return (0);

	bo = malloc(100);
	if(!bo)
	{
		free(buffer);
		return (0);
		close(fd);
	}
	bo[0] = '\0';

	
	while((numRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		temp =malloc(numRead + 1);
		if(!temp)
		{
			free(buffer);
			close(fd);
			return (0);
		}
		memcpy(temp, buffer, numRead);
		temp[numRead] = '\0';
	
		if(strchr(temp, '\n') != NULL)
		{
			reserve = malloc(numRead + 1);
			if(!reserve)
			{
				free(buffer);
				free(temp);
				close(fd);
				return (0);
			}
			strcpy(reserve, temp);
		}
	}

	strncat(bo, temp, numRead);
	free(temp);
	printf("%s\n", bo);


	close(fd);

	return 0;
}
