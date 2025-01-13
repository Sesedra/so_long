/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:08:21 by srabeman          #+#    #+#             */
/*   Updated: 2024/04/15 12:06:06 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		i;

	length = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ft_handle_format(format[i + 1], args, &length);
			i++;
		}
		else if (format[i] != '%')
			ft_putchar(format[i], &length);
		else
			return (length);
	}
	va_end(args);
	return (length);
}
