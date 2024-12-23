/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:32:26 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/10 11:11:16 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_itoa(int n);
int		ft_puthex(unsigned long n);
int		ft_putptr(void *ptr);
int		ft_putunbr(unsigned int n);
int		ft_puthex_u(unsigned long n);

#endif
