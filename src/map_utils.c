/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:15:27 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/19 15:49:00 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_format(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len - 3] == '.' && str[len - 2] == 'b' && \
	str[len - 1] == 'e' && str[len] == 'r')
		return (0);
	return (1);
}

int	print_error(char *str)
{
	ft_printf("\033[1;31m Error \033[0m\n");
	ft_printf("\033[1;31m %s \033[0m\n", str);
	exit (1);
}

void	init(t_data *data, char *map_path)
{
	data->map.path = map_path;
	data->is_winning = 0;
	data->map.collectibles = 0;
	data->map.start_count = 0;
	data->map.exit = 0;
	data->map.map_height = 0;
	data->map.map_width = 0;
	data->move = 0;
	data->map.exit_accessibles = 0;
}

int	line_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char **copy_map(char **map)
{
	int i;
	char **copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return NULL;
	i = 0;
	while (map[i])
	{
		copy[i] = strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return copy;
}

void free_map(char **map)
{
	int i; 
	
	i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
