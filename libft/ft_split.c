/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:41:28 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/02 13:27:24 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_c(const char *str, char delim)
{
	size_t	count;

	if (!s)
		return (NULL);
	count = 0;
	while (*str)
	{
		if (*str == delim)
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

char	*word_dup(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char del)
{
	char		**string;
	size_t		i;
	size_t		len;

	string = (char **)malloc(sizeof(char *) * (word_c(s, del) + 1));
	if (!s || !string)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == del)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, del))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, del) - s;
			string[i++] = ft_substr(s, 0, len);
			s += len;
		}
	}
	string[i] = NULL;
	return (string);
}
