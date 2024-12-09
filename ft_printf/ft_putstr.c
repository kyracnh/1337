/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:34:20 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/09 09:48:58 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int c;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i] != '\0')
	{
		c = write(1, &str[i], 1);
		if (c == -1)
			return (-1);
		i++;
	}
	return (i);
}
