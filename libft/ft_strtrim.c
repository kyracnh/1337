/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:31:07 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/28 11:51:58 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_start(char const *s1, char const *set, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < s_len && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

size_t	ft_end(char const *s1, char const *set, size_t s_len)
{
	size_t	i;

	i = 0;
	while (s1 < s_len && ft_strchr(set, s1[s_len - i - 1]))
		i++;
	return (s_len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;
	char 	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	s_len = ft_strlen(s1);
	start = ft_start(s1, set, s_len);
	end = ft_end(s1, set, s_len);
	if (start >= end)
		return (ft_strdup(""));
	trim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trim)
		return (NULL);
	
}
