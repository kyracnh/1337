/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:30:31 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/07 09:32:02 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
			{
				char	c;
				
				c = va_arg(args, int);
				ft_putchar(c);
			}
			// add more specifiers here ..........
			else if (format[i] == 's')
			{
				char	*str;
				
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				ft_putstr(str);
			}
			// add more specifiers here ..........
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int	num;
				char	*str;
				
				num = va_arg(args, int);
				str = ft_itoa(num);
				write(1, str, ft_strlen(str));
				free(str);
			}
			// add more specifiers here ..........
		}
		else
			write(1, &format[i],1);
		i++;
	}
	va_end(args);
	return (i);
}
