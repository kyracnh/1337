/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:51:26 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/30 18:19:15 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *line, char **reserve, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*newline_pos;
	ssize_t	numRead;
	size_t	line_len;
	size_t	total_len;

	total_len = 0;
	while ((numRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[numRead] = '\0';
		newline_pos = strchr(buffer, '\n');
		if (newline_pos)
		{
			line_len = newline_pos - buffer + 1;
			line = realloc(line, total_len + line_len + 1);
			if (!line)
				return (NULL);
			strncat(line, buffer, line_len);
			*reserve = strdup(newline_pos + 1);
			if (!*reserve)
				return (NULL);
			return (line);
		}
		line = realloc(line, total_len + numRead + 1);
		if (!line)
		{
			line = malloc(1);
			if (!line)
				return (NULL);
			line[0] = '\0';
		}
		strncat(line, buffer, numRead);
		total_len += numRead;
	}
	if (numRead == 0 && line && total_len > 0)
		return (line);
	free(line);
	return (NULL);
}

char	*check_reserve(char *line, char **reserve)
{
	if (*reserve)
	{
		line = strdup(*reserve);
		if (!line)
			return (NULL);
		free(*reserve);
		*reserve = (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char	*line;

	reserve = NULL;
	line = NULL;
	line = check_reserve(line, &reserve);
	line = get_line(line, &reserve, fd);
	return (line);
}
