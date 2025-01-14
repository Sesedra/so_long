/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:46:35 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/14 13:37:53 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	parse_map(t_map *map)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(map->path, O_RDONLY);
// 	if (fd < 0)
// 		print_error("Map introuvable");
// 	map->map_height = 0;
// 	map->map_width = 0;
// 	line = get_next_line(fd);
// 	map->map_width = line_count(line);
// 	while (line)
// 	{
// 		map->map_height++;
// 		if (line_count(line) != map->map_width)
// 			print_error("Le map n'est pas rectangulaire");
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	if (map->map_height == 0)
// 		print_error("Map vide");
// 	ft_printf("VAleur de map_width; %d", map->map_width);
// 	ft_printf("VAleur de map_height; %d", map->map_height);
// 	return (1);
// }

int	parse_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		print_error("Map introuvable");
	map->map_height = 0;
	map->map_width = 0;

	line = get_next_line(fd);
	if (!line)
		print_error("Map vide ou erreur de lecture");

	map->map_width = line_count(line);

	while (line)
	{
		if (line_count(line) != map->map_width)
		{
			free(line);
			close(fd);
			print_error("Le map n'est pas rectangulaire");
		}
		map->map_height++;
		free(line);
		line = get_next_line(fd);
	}

	close(fd);

	if (map->map_height == 0)
		print_error("Map vide");

	ft_printf("Valeur de map_width: %d\n", map->map_width);
	ft_printf("Valeur de map_height: %d\n", map->map_height);
	ft_printf("Vita ny parse map");

	return (1);
}


void	check_walls(t_map *map)
{
	int	i;
	int	j;

	i =  0;
	ft_printf("Miditra verification voalohany \n");
	while (i < map->map_width)
	{
		if (map->map[0][i] != '1' || map->map[map->map_height - 1][i] != '1')
			print_error("La carte doit etre entoure de de murs");
		i++;
	}

	ft_printf("Miditra verification faharoa \n");

	j =  0;
	while (j < map->map_height)
	{
		if (map->map[j][0] != '1' || map->map[j][map->map_width - 1] != '1')
			print_error("La carte doit etre entoure de de murs");
		j++;
	}
}


void	load_map(t_map *map)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;
	map->map = malloc((map->map_height + 1) * sizeof(char *));
	if (!map->map)
		print_error("Erreur de l'allocation de memoire");
	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		print_error("Map introuvable");
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map[i] = line;
		i++;
		ft_printf("%d ligne ajoutee \n", i);
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	close(fd);
}

void check_map_elt(t_map *map)
{
	int	i;
	int	j;

	
	j = 0;
	while (j < map->map_height)
	{
		i = 0;
		while (i < map->map_width)
		{
			if (map->map[j][i] == 'C')
				map->collectibles++;
			else if (map->map[j][i] == 'E')
				map->exit++;
			else if (map->map[j][i] == 'P')
				map->start++;
			else if (map->map[j][i] != '0' && map->map[j][i] != '1')
				print_error("Unknown character found");
			i++;
		}
		j++;
	}

	if (map->exit != 1)
		print_error("Nombre de sortie incorrect");
	if (map->start != 1)
		print_error("Nomnbre de position de depart incorrect");
	if (map->collectibles == 0)
		print_error("Aucun collectible detecte");
}

void	init_map_sprites(t_data *data)
{
	ft_printf("Valeur de map_width dans init sprite AVANT: %d\n", data->map.map_width);
	ft_printf("Valeur de map_height: %d\n", data->map.map_height);
	data->collectible_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/c_sp.xpm", &data->collectible_sprite.sprite_w, &data->collectible_sprite.sprite_h);
	data->exit_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/e_sp.xpm", &data->exit_sprite.sprite_w, &data->exit_sprite.sprite_h);
	data->wall_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/w_sp.xpm", &data->wall_sprite.sprite_w, &data->wall_sprite.sprite_h);
	data->start_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/s_sp.xpm", &data->start_sprite.sprite_w, &data->start_sprite.sprite_h);
	data->floor_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/f_sp.xpm", &data->floor_sprite.sprite_w, &data->floor_sprite.sprite_h);
	// data->exit_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/e_sp.xpm", &data->map., &data->map.map_height);
	// data->wall_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/w_sp.xpm", &data->map.map_width, &data->map.map_height);
	// data->start_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/s_sp.xpm", &data->map.map_width, &data->map.map_height);
	// data->floor_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/f_sp.xpm", &data->map.map_width, &data->map.map_height);
	ft_printf("Valeur de map_width dans init sprite APRES: %d\n", data->map.map_width);
	ft_printf("Valeur de map_height: %d\n", data->map.map_height);
}	

void	draw_bg(t_data *data)
{
	t_position	start;
	t_position	exit;

	start.pos_x = 0;
	start.pos_y = 0;
	exit.pos_x = data->map.map_width * SIZE;
	exit.pos_y = data->map.map_height * SIZE;
	while (start.pos_y < exit.pos_y)
	{
		while (start.pos_x < exit.pos_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor_sprite.img, start.pos_x, start.pos_y);
			start.pos_x += SIZE;
		}
		start.pos_x = 0;
		start.pos_y += SIZE;
	}
}

void	draw_map(t_data *data)
{
	t_position	start;
	t_position	exit;

	start.pos_x = 0;
	start.pos_y = 0;
	exit.pos_x = (data->map.map_width) * SIZE;
	exit.pos_y = (data->map.map_height) * SIZE;
	ft_printf("x = %d\n", (data->map.map_width));
	ft_printf("y = %d\n\n", (data->map.map_height));

	while (start.pos_y < exit.pos_y)
	{
		while (start.pos_x < exit.pos_x)
		{
			if (data->map.map[start.pos_y / SIZE][start.pos_x / SIZE] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->wall_sprite.img, start.pos_x, start.pos_y);
			else if (data->map.map[start.pos_y / SIZE][start.pos_x / SIZE] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->collectible_sprite.img, start.pos_x, start.pos_y);
			else if (data->map.map[start.pos_y / SIZE][start.pos_x / SIZE] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->start_sprite.img, start.pos_x, start.pos_y);
			else if (data->map.map[start.pos_y / SIZE][start.pos_x / SIZE] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->exit_sprite.img, start.pos_x, start.pos_y);
			// if (data->map.map[start.pos_y / SIZE][start.pos_x / SIZE] == 'C')
			// 	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->collectible_sprite.img, start.pos_x, start.pos_y);

			start.pos_x += SIZE;
		}
		start.pos_x = 0;
		start.pos_y += SIZE;
	}
}