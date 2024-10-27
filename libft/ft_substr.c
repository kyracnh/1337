/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:43:10 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/27 18:43:15 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	j;
	size_t	i;

	j = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= j)
		return (ft_strdup(""));
	if (len > j - start)
		len = j - start;
	string = (char *)malloc(len + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = s[start + i];
		i++;
	}
	string[len] = '\0';
	return (string);
}
