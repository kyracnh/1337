/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:08:43 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/27 10:09:23 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*block1;
	unsigned char	*block2;
	size_t			i;

	block1 = (unsigned char *)s1;
	block2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (!(block1[i] == block2[i]))
		{
			return (block1[i] - block2[i]);
		}
		i++;
	}
	return (0);
}
