/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:41:28 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/02 13:29:32 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Helper function to free allocated memory in case of an error
static void	free_split(char **split, int words) {
	for (int i = 0; i < words; i++) {
		if (split[i]) {
			free(split[i]);
		}
	}
	free(split);
}

// Helper function to count words separated by delimiter
int	word_c(const char *str, char delim) {
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (*str) {
		while (*str == delim)
			str++;
		if (*str) {
			count++;
			while (*str && *str != delim)
				str++;
		}
	}
	return (count);
}

// Modified ft_split with malloc checks
char	**ft_split(const char *s, char del) {
	char	**string;
	int		i = 0;
	size_t	len;

	string = (char **)malloc(sizeof(char *) * (word_c(s, del) + 1));
	if (!string)
		return (NULL);
	while (*s) {
		while (*s == del && *s)
			s++;
		if (*s) {
			if (!ft_strchr(s, del))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, del) - s;
			string[i] = ft_substr(s, 0, len);
			if (!string[i]){  // Check if malloc failed in ft_substr
				free_split(string, i);  // Free already allocated memory
				return (NULL);
			}
			i++;
			s += len;
		}
	}
	string[i] = NULL;
	return (string);
}
