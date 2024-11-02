/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:41:28 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/01 21:24:17 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c) {
    int	count = 0;
    int	in_word = 0;

    while (*str) {
        if (*str != c && !in_word) {
            in_word = 1;
            count++;
        } else if (*str == c) {
            in_word = 0;
        }
        str++;
    }
    return count;
}

static char	*word_dup(const char *start, size_t len) {
    char	*word;

	word = (char *)malloc(len + 1);
    if (!word)
        return NULL;
    ft_strlcpy(word, start, len + 1);
    return word;
}

char	**ft_split(const char *s, char c) {
    char	**split;
    size_t	word_c;
    size_t	i;
    size_t	len;

    if (!s)
        return NULL;

    word_c = word_count(s, c);
    split = (char **)malloc((word_c + 1) * sizeof(char *));
    if (!split)
        return NULL;

    i = 0;
    while (*s) {
        while (*s == c)
            s++;
        if (*s) {
            len = 0;
            while (s[len] && s[len] != c)
                len++;
            split[i++] = word_dup(s, len);
            s += len;
        }
    }
    split[i] = NULL;
    return split;
}