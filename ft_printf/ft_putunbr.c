/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:55:15 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/09 09:34:45 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	c;

	c = 0;
	if (n >= 10)
		c += ft_putunbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (c + 1);
}
