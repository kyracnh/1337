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

static int	count_word(const char *s, char c)
{
	int	i;
	int	wc;
	int	temp;

	i = 0;
	wc = 0;
	temp = 0;
	while (s[i])
	{
		if (s[i] == c)
			temp = 0;
		else if (temp == 0)
		{
			temp = 1;
			wc++;
		}
		i++;
	}
	return (wc);
}

static void	*free_split(char **split, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**to_split(char *s, char c, char **split)
{
	int	i;
	int	k;
	int	p;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			p = i;
			while (s[i] != c && s[i])
				i++;
			split[k++] = ft_substr(s, p, i - p);
			if (!split[k - 1])
				return (free_split(split, k));
		}
		else
			i++;
	}
	split[k] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = to_split((char *)s, c, split);
	return (split);
}
