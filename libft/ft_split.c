/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:41:28 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/04 23:43:34 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **split, int w)
{
	int	i;

	i = 0;
	while (i < w)
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

int	word_c(const char *str, char delim)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == delim)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != delim)
				str++;
		}
	}
	return (count);
}

static char	**make_split(char *s, char del, char **string)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == del)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, del))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, del) - s;
			string[i] = ft_substr(s, 0, len);
			if (!string[i])
				return (free_split(string, i));
			i++;
			s += len;
		}
	}
	string[i] = NULL;
	return (string);
}

char	**ft_split(const char *s, char del)
{
	char	**string;

	if (!s || !del)
		return (NULL);
	string = (char **)malloc(sizeof(char *) * (word_c(s, del) + 1));
	if (!string)
		return (NULL);
	string = make_split((char *)s, del, string);
	return (string);
}
