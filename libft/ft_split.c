/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:41:28 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/03 14:38:45 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}

int	word_c(const char *str, char delim)
{
	size_t	count;

	if (!str)
		return (0);
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

char	**ft_split(const char *s, char del)
{
	char	**string;
	int		i;
	size_t	len;

	i = 0;
	string = (char **)malloc(sizeof(char *) * (word_c(s, del) + 1));
	if (!string)
		return (NULL);
	while (*s)
	{
		while (*s == del && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, del))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, del) - s;
			string[i] = ft_substr(s, 0, len);
			if (!string[i])
			{
				free_split(string, i);
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	string[i] = NULL;
	return (string);
}
