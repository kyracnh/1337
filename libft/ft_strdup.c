/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:24:32 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/27 10:24:36 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	char	*str;
	int		i;
	int		len;

	str = (char *)s;
	len = ft_strlen(s);
	string = (char *)malloc(len * sizeof(char) + 1);
	i = 0;
	if (!string)
		return (NULL);
	while (i < len && s)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
