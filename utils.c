/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:15:27 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/10 16:48:28 by srabeman         ###   ########.fr       */
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
    ft_printf("\033[1;31m⚙️ %s :\033[0m\n", str);
		return (0);
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
    while (line)
    {
        map->map_height++;
        map->map_width = line_count(line);
        if (map->map_width != line_count(line))
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