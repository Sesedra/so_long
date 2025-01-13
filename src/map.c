/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:46:35 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/13 15:17:45 by srabeman         ###   ########.fr       */
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
