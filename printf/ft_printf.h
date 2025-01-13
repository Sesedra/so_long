/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:36:38 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/10 14:46:58 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c, int *length);
void	ft_putstr(const char *str, int *length);
void	ft_putaddress(void *p, int *length);
void	ft_putnbr(int nbr, int *length);
void	ft_putuns_nbr(unsigned long nbr, int *length);
void	ft_puthex_upp(unsigned long nbr, int *length);
void	ft_puthex_low(unsigned long nbr, int *length);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
void	ft_handle_format(char c, va_list var_args, int *length);
int		ft_printf(const char *format, ...);

#endif
