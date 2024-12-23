/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:52:55 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/08 13:02:47 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n)
{
	int	c;

	c = 0;
	if (n >= 16)
		c += ft_puthex(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	return (c + 1);
}
