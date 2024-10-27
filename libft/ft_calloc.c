/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:05:30 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/27 10:22:56 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	char	*s;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	s = (char *)malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
