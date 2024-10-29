/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:41:28 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/28 14:54:20 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int word_c(const char *str, char delim)
{
    size_t  count;

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

char    *word_dup(const char *start, size_t len)
{
    char    *word;
    size_t  i;

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
	char    **string;
    const char    *start;
    size_t  words;
    size_t  i;
    size_t  len;

    if (!s)
        return (NULL);
    words = word_c(s, del);
    string = (char **)malloc(sizeof(char *) * (words + 1));
    if (!string)
        return (NULL);
    i = 0;
    while (*s)
    {
        while (*s == del)
            s++;
        if (*s)
        {
            start = s;
            len = 0;
            while (*s && *s != del)
            {
                len++;
                s++;
            }
            string[i++] = word_dup(start, len);
        }
    }
    string[i] = NULL;
    return (string);
}
