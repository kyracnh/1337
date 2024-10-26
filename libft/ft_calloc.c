/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:05:30 by aanmazir          #+#    #+#             */
/*   Updated: 2024/10/26 14:49:13 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	size_t	n;
	int	i;
	void	*s;
	void	**b;
	int	max;

	s = malloc(sizeof(int));
	if (!s)
		return (NULL);

	max = 2^48;
	if (size > max)
		return (NULL);
	n = nmemb;
	b = 0;
	i = 0;
	while (i < n)
	{
		b += s;
		ft_bzero(b, nmemb);
		i++;
	}
}
