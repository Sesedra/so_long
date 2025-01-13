/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:02:10 by srabeman          #+#    #+#             */
/*   Updated: 2024/04/15 13:37:51 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_low(unsigned long nbr, int *length)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthex_low(nbr / 16, length);
		ft_puthex_low(nbr % 16, length);
	}
	else
		ft_putchar(base_hex[nbr], length);
}
