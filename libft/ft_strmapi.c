/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:05:36 by aanmazir          #+#    #+#             */
/*   Updated: 2024/11/01 16:12:37 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nat;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	nat = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nat)
		return (NULL);
	i = 0;
	while (s[i])
	{
		nat[i] = f(i, s[i]);
		i++;
	}
	nat[i] = '\0';
	return (nat);
}
