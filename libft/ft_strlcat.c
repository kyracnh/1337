/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:07:00 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/27 14:10:40 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (dest == NULL && destsize == 0)
		return (ft_strlen(src));
	if (destsize == 0 || len_dest >= destsize)
		return (len_src + destsize);
	i = 0;
	while (src[i] != '\0' && i < destsize - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}
