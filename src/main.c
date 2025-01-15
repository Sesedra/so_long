/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:21 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/14 14:12:36 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "printf.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
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
	init(&data, argv[1]);
	parse_map(&data.map);
	load_map(&data.map);
	check_walls(&data.map);
	check_map_elt(&data.map);
	check_player_position(&data);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.map.map_width * SIZE, \
	data.map.map_height * SIZE, "So long");
	data.mlx_img = mlx_new_image(data.mlx_ptr, data.map.map_width * SIZE, \
	data.map.map_height * SIZE);
	data.mlx_addr = mlx_get_data_addr(data.mlx_img, &data.bppx, \
	&data.size_line, &data.endian);
	init_map_sprites(&data);
	draw_bg(&data);
	draw_map(&data);
	draw_player(&data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, \
	&on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	free(data.map.map);

}
