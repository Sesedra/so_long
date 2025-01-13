/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:56:31 by srabeman          #+#    #+#             */
/*   Updated: 2024/04/15 14:55:49 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *length)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", length);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', length);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, length);
		ft_putchar(nbr % 10 + '0', length);
	}
	else
		ft_putchar(nbr + '0', length);
}
