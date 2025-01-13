/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:03:31 by srabeman          #+#    #+#             */
/*   Updated: 2024/04/15 13:46:43 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress(void *p, int *length)
{
	unsigned long	n;

	if (!p)
		ft_putstr("(nil)", length);
	else
	{
		n = (unsigned long)p;
		ft_putstr("0x", length);
		ft_puthex_low(n, length);
	}
}
