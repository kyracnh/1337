#include "get_next_line.h"

char	*read_line(int fd, char *buf)
{
	char	*tmp;
	char	*join;
	int		i;

	join = (char *)malloc(BUFFER_SIZE + 1);
	if (!join)
		return (NULL);
	i = read(fd, join, BUFFER_SIZE);
	if (i < 0)
		return (free_it(join, buf));
	while (i > 0)
	{
		if (i < 0)
			return (free_it(join, buf));
		join[i] = '\0';
		tmp = ft_strjoin(buf, join);
		free(buf);
		buf = tmp;
		if (ft_strchr(buf, '\n') > -1)
			break ;
		i = read(fd, join, BUFFER_SIZE);
	}
	free(join);
	return (buf);
}

char	*get_the_line(char *buf)
{
	char	*new_line;
	int		i;
	int		j;

	if (!buf)
		return (NULL);
	if (buf[0] == '\0')
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	new_line = (char *)malloc(i + 2);
	if (!new_line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		new_line[j] = buf[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

char	*get_the_rest(char *buf)
{
	char	*rest;
	int		i;

	i = 0;
	if (!buf)
		return (free(buf), NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	i++;
	rest = ft_strdup(buf + i);
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*len;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (free(buf), NULL);
	buf = read_line(fd, buf);
	len = get_the_line(buf);
	buf = get_the_rest(buf);
	return (len);
}