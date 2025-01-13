/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:04:45 by srabeman          #+#    #+#             */
/*   Updated: 2024/04/15 14:57:17 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *str, int *length)
{
	if (!str)
	{
		*length += 6;
		write(1, "(null)", 6);
	}
	else
		while (*str)
			ft_putchar(*str++, length);
}
