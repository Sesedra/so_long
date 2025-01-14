/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:46:35 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/14 09:05:42 by srabeman         ###   ########.fr       */
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
	map->map_width = line_count(line);
	while (line)
	{
		map->map_height++;
		if (line_count(line) != map->map_width)
			print_error("Le map n'est pas rectangulaire");
		line = get_next_line(fd);
	}
	close(fd);
	if (map->map_height == 0)
		print_error("Map vide");
	return (1);
}

void	check_walls(t_map *map)
{
	size_t	i;
	size_t	j;

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
	size_t	i;
	size_t	j;

	
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