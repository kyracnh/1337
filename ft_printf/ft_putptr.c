/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:53:48 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/08 13:05:31 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				c;

	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	addr = (unsigned long)ptr;
	c = 0;
	c += ft_putchar('0');
	c += ft_putchar('x');
	if (addr == 0)
		c += ft_putchar('0');
	else
		c += ft_puthex(addr);
	return (c);
}
