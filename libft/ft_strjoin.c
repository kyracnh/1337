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

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	string = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, ft_strlen(s1) + 1);
	ft_strlcat(string, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (string);
}
