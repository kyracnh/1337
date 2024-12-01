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

char	*get_line(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*str;
	char	*res;
	ssize_t	numRead;
	size_t	line_len;
	size_t	tlen;

	tlen = 0;
	str = (char *)malloc(BUFFER_SIZE);
	if (!str)
	return (NULL);
	while ((numRead = read(fd, str, BUFFER_SIZE)) > 0)
	{
		buffer[numRead] = '\0';
		res = ft_strjoin(line, str);
		free(line);
		buf = res;
		if (ft_strchr(buf, '\n') > -1)
			break ;
		numRead = read(fd, str, BUFFER_SIZE);
	}
	free(str);
	return (buf);
}

char	*print_line(char *reserve)
{
	
}

char	*check_reserve(char *reserve)
{
	char *line;

	if (reserve)
	{
		line = strdup(reserve);
		if (!line)
			return (NULL);
		free(reserve);
		reserve = (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = get_line(reserve, fd);
	line = print_line(reserve);
	reserve = check_reserve(reserve);
	return (line);
}
