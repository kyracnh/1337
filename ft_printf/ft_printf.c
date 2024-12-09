/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:30:31 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/09 13:35:03 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_sps(va_list args, char format)
{
	int		i;
	char	*str;

	i = 0;
	if (format == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (format == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
	{
		str = ft_itoa(va_arg(args, int));
		i = ft_putstr(str);
		free(str);
	}
	else if (format == 'p')
		i = ft_putptr(va_arg(args, void *));
	else if (format == 'u')
		i = ft_putunbr(va_arg(args, unsigned int));
	else if (format == '%')
		i = ft_putchar('%');
	else if (format == 'x')
		i = ft_puthex(va_arg(args, unsigned int));
	else if (format == 'X')
		i = ft_puthex_u(va_arg(args, unsigned int));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		o;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if ((o = format_sps(args, format[i])) == -1)
				return (-1);
			len += o;
		}
		else
		{
			if ((write(1, &format[i], 1)) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	return (va_end(args), len);
}
