/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:07:57 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/27 10:08:02 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t len)
{
	unsigned char	*block;
	size_t			i;

	block = (unsigned char *)buf;
	i = 0;
	while (i < len)
	{
		block[i] = (unsigned char)c;
		i++;
	}
	return (block);
}
