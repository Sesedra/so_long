/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:15:27 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/13 11:32:34 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_format(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len - 3] == '.' && str[len - 2] == 'b' && str[len - 1] == 'e' && str[len] == 'r')
		return (0);
	return (1);
}

int    print_error(char *str)
{
    ft_printf("\033[1;31m Error \033[0m\n");
    ft_printf("\033[1;31m %s \033[0m\n", str);
	exit (1);
}

void    init(t_data *data, char *map_path)
{
    data->map.path = map_path;
}

int parse_map(t_map *map)
{
    int     fd;
    char    *line;

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

size_t  line_count(char *str)
{
    size_t  i;

    i = 0;
    while (str[i] && str[i]!= '\n')
        i++;
    return (i);
}

int init_grid(t_data *data)
{
    t_position  position;
    char    *line;
    init_fill(data, &position);
    line = get_next_line(data->map.fd);
    while (line)
    {
        data->map.grid[position.pos_x] = malloc((data->map.map_width - 1) * sizeof(char));
        data->map.grid[position.pos_y] = malloc((data->map.map_width - 1) * sizeof(char));
    }
}

void    init_fill(t_data *data, t_position *pos)
{
    data->map.path = open(data->map.fd, O_RDONLY);
    data->map.grid = malloc(data->map.map_height*sizeof(char *));
    data->map.tiles = malloc(data->map.map_height*sizeof(char));
    pos->pos_x = 0;
    pos->pos_y = 0;
}

int	check_walls(t_data *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while(x < data->map.map_width)
	{
		if (data->map.grid[x][y] != '1')
			print_error("Erreur dans les murs");
		
	}
}