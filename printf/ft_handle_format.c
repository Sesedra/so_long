/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:08:54 by srabeman          #+#    #+#             */
/*   Updated: 2024/04/15 13:47:39 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_format(char c, va_list var_args, int *length)
{
	if (c == 'c')
		ft_putchar((char)va_arg(var_args, int), length);
	else if (c == 's')
		ft_putstr((char *)va_arg(var_args, char *), length);
	else if (c == 'p')
		ft_putaddress((char *)va_arg(var_args, unsigned long), length);
	else if (c == 'd')
		ft_putnbr((long)va_arg(var_args, int), length);
	else if (c == 'i')
		ft_putnbr((long)va_arg(var_args, int), length);
	else if (c == 'u')
		ft_putuns_nbr((unsigned long)va_arg(var_args, unsigned int), length);
	else if (c == 'x')
		ft_puthex_low((unsigned long)va_arg(var_args, unsigned int), length);
	else if (c == 'X')
		ft_puthex_upp((unsigned long)va_arg(var_args, unsigned int), length);
	else if (c == '%')
		ft_putchar(c, length);
}
