/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:21 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/10 16:31:50 by srabeman         ###   ########.fr       */
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
	t_data	data;

	if (argc == 1)
		print_error("Carte introuvable");
	else if (argc > 2)
		print_error("Argument invalide");
	else if (check_map_format(argv[1]))
		print_error("Map invalide");

	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 500, 500, "So long");
	mlx_loop(data.mlx_ptr);
}
