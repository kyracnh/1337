/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:51:26 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/04 18:20:51 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_line(int fd, char *res)
{
	char	*temp;
	char	*str;
	ssize_t	re;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	re = read(fd, str, BUFFER_SIZE);
	if (re < 0)
		return (double_free(str, res), NULL);
	while (re > 0)
	{
		if (re < 0)
			return (double_free(str, res), NULL);
		str[re] = '\0';
		temp = ft_strjoin(res, str);
		free(res);
		res = temp;
		if (ft_strchr(res, '\n') > -1)
			break ;
		re = read(fd, str, BUFFER_SIZE);
	}
	free(str);
	return (res);
}

char	*print_line(char *res)
{
	char	*newline;
	int		i;
	int		j;

	if (!res)
		return (NULL);
	if (res[0] == '\0')
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	newline = malloc(i + 2);
	if (!newline)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		newline[j] = res[j];
		j++;
	}
	newline[j] = '\0';
	return (newline);
}

char	*get_reserve(char *res)
{
	char	*last;
	int		i;

	if (!res)
		return (free(res), NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
		return (free(res), NULL);
	i++;
	last = ft_strdup(res + i);
	if (!last)
		return (free(res), NULL);
	free(res);
	return (last);
}

char	*get_next_line(int fd)
{
	static char	*res[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (free(res), NULL);
	res = get_the_line(fd, res[fd]);
	line = print_line(res[fd]);
	res = get_reserve(res[fd]);
	return (line);
}
