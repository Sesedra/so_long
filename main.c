/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:21 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/10 15:06:05 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "printf.h"

int	check_map_format(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len - 3] == '.' && str[len - 2] == 'b' && str[len - 1] == 'e' && str[len] == 'r')
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_printf("Map introuvable \n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_printf("Argument invalide \n");
		return (0);
	}
	else if (check_map_format(argv[1]))
	{
		ft_printf("Map invalide \n");
		return (0);
	}
}
