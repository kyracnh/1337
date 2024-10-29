/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:38:36 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/26 16:29:10 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	ch;

	ch = (char) c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
