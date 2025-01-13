/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:00:41 by srabeman          #+#    #+#             */
/*   Updated: 2024/04/15 13:37:38 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_upp(unsigned long nbr, int *length)
{
	char	*base_hex;

	base_hex = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_puthex_upp(nbr / 16, length);
		ft_puthex_upp(nbr % 16, length);
	}
	else
		ft_putchar(base_hex[nbr], length);
}
