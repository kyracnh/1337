#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

char *get_next_line(int fd)
{
    static char *reserve = NULL;
    char buffer[BUFFER_SIZE + 1];
    char *line = NULL;
    ssize_t numRead;
    size_t total_len = 0;

    if (reserve)
    {
        line = strdup(reserve);
        if (!line)
            return NULL;
        free(reserve);
        reserve = NULL;
    }

    while ((numRead = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[numRead] = '\0';

        char *newline_pos = strchr(buffer, '\n');
        if (newline_pos)
        {
            size_t line_len = newline_pos - buffer + 1;
            line = realloc(line, total_len + line_len + 1);
            if (!line)
                return NULL;

            strncat(line, buffer, line_len);

            reserve = strdup(newline_pos + 1);
            return line;
        }

        line = realloc(line, total_len + numRead + 1);
        if (!line)
            return NULL;

        strncat(line, buffer, numRead);
        total_len += numRead;
    }

    if (numRead == 0 && line && total_len > 0)
        return line;

    free(line);
    return NULL;
}

int main(void)
{
    int fd = open("ahmed.txt", O_RDONLY);
    if (fd == -1)
        return 1;

    char *line;
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
        free(line);

    close(fd);
    return 0;
}
