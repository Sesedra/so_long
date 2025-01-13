/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:59:52 by srabeman          #+#    #+#             */
/*   Updated: 2024/04/15 14:58:09 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuns_nbr(unsigned long nbr, int *length)
{
	if (nbr >= 10)
	{
		ft_putuns_nbr(nbr / 10, length);
		ft_putchar(nbr % 10 + '0', length);
	}
	else
		ft_putchar(nbr + '0', length);
}
