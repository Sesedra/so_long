/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:46:35 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/16 12:38:34 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			{
				map->start_count++;
				map->start.pos_x = i;
				map->start.pos_y = j;
			}
			else if (map->map[j][i] != '0' && map->map[j][i] != '1')
				print_error("Unknown character found");
			i++;
		}
		j++;
	}

	if (map->exit != 1)
		print_error("Nombre de sortie incorrect");
	if (map->start_count != 1)
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
	data->player.sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/p_sp.xpm", &data->player.sprite.sprite_w, &data->player.sprite.sprite_h);
	data->exitplayer_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/pe_sp.xpm", &data->exitplayer_sprite.sprite_w, &data->exitplayer_sprite.sprite_h);
	data->startplayer_sprite.img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/se_sp.xpm", &data->startplayer_sprite.sprite_w, &data->startplayer_sprite.sprite_h);
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
	// ft_printf("x = %d\n", (data->map.map_width));
	// ft_printf("y = %d\n\n", (data->map.map_height));

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
			else if (data->map.map[start.pos_y / SIZE][start.pos_x / SIZE] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor_sprite.img, start.pos_x, start.pos_y);
			// if (data->map.map[start.pos_y / SIZE][start.pos_x / SIZE] == 'C')
			// 	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->collectible_sprite.img, start.pos_x, start.pos_y);

			start.pos_x += SIZE;
		}
		start.pos_x = 0;
		start.pos_y += SIZE;
	}
}



void	draw_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player.sprite.img, data->player.position.pos_x * SIZE, data->player.position.pos_y * SIZE);
}

void check_player_position(t_data *data)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < data->map.map_height)
	{
		i = 0;
		while (i < data->map.map_width)
		{
			if (data->map.map[j][i] == 'P')
			{
				data->player.position.pos_x = i;
				data->player.position.pos_y = j;
				return;
			}	
			i++;
		}
		j++;
	}
}

void	check_victory(t_data *data)
{
	char	current_position = data->map.map[data->player.position.pos_x][data->player.position.pos_y];

	if (current_position)
	{
		if (data->map.collectibles == 0)
		{
			ft_printf("Vous avez gagné \n");
			exit(1); 
		}
	}
	else
	{
		ft_printf("Collecter toutes les collectibles pour continuer \n");
	}
}

void	move_player(t_data *data, int move_x, int move_y)
{
	int	new_x;
	int new_y;

	new_x = data->player.position.pos_x + move_x;
	new_y = data->player.position.pos_y + move_y;

	if (data->map.map[new_y][new_x] == '1')
		return;
	else data->move++;
	if (data->map.map[new_y][new_x] == 'C')
		data->map.collectibles--;
	if (data->map.map[new_y][new_x] == 'E' && data->map.collectibles == 0)
	{
		ft_printf("You won \n");
		exit(1);
	}
	else
	{
		ft_printf("Collect them all \n");
	}
	if (data->player.position.pos_x == data->map.start.pos_x && data->player.position.pos_y == data->map.start.pos_y)
	{
		data->map.map[data->player.position.pos_y][data->player.position.pos_x] = 'S';
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->start_sprite.img,
								data->player.position.pos_x * SIZE,
								data->player.position.pos_y * SIZE);
	}
	else if (data->map.map[data->player.position.pos_y][data->player.position.pos_x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->exit_sprite.img,
								data->player.position.pos_x * SIZE,
								data->player.position.pos_y * SIZE);
	}
	else
	{
		data->map.map[data->player.position.pos_y][data->player.position.pos_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr,data->mlx_win,
								data->floor_sprite.img,
								data->player.position.pos_x * SIZE,
								data->player.position.pos_y * SIZE );
	}
	data->player.position.pos_x = new_x;
	data->player.position.pos_y = new_y;
	if (data->map.map[new_y][new_x] == 'E' && data->map.collectibles > 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->exitplayer_sprite.img,
								new_x * SIZE,
								new_y * SIZE
								);
	}
	else
	{
	data->map.map[new_y][new_x] = 'P';
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
							data->player.sprite.img,
							new_x * SIZE,
							new_y * SIZE);
	}

	ft_printf("Move: %d \n", data->move);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == XK_S || keycode == XK_s)
		move_player(data, 0, 1);
	else if (keycode == XK_W || keycode == XK_w)
		move_player(data, 0, -1);
	else if (keycode == XK_A || keycode == XK_a)
		move_player(data, -1, 0);
	else if (keycode == XK_D || keycode == XK_d)
		move_player(data, 1, 0);
	else if (keycode == XK_Escape)
		on_destroy(data);
	return (0); 
}

void	flood_fill(char **map, int x, int y, int *collectibles, bool *exit_found)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0')
		return;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	if (map[y][x] == 'C')
		(*collectibles)--;
	if (map[y][x] == 'E')
		*exit_found = true;
	map[y][x] == 'V';

	flood_fill(map, x + 1, y, collectibles, exit_found);
	flood_fill(map, x - 1, y, collectibles, exit_found);
	flood_fill(map, x , y + 1, collectibles, exit_found);
	flood_fill(map, x , y - 1, collectibles, exit_found);
}

bool	validate_map(char **map, int start_x, int start_y, int collectibles_count)
{
	bool	exit_found;
	char	**map_copy;

	exit_found = false;
	map_copy = copy_map(map);
	flood_fill(map_copy, start_x, start_y, collectibles_count, exit_found);
	free_map(map_copy);
	return (collectibles_count == 0 && exit_found);
}