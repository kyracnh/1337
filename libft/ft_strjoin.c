/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:42:16 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/27 21:50:43 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	l1;
	int		i;
	int		j;

	l1 = ft_strlen(s1);
	string = (char *)malloc(l1 + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		string[l1] = s2[j];
		j++;
		l1++;
	}
	string[l1] = '\0';
	return (string);
}
