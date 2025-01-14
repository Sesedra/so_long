/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:52 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/14 14:12:47 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#ifndef SIZE
	# define SIZE 50
#endif
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../get_next_line/get_next_line.h"
#include "../printf/ft_printf.h"
#include "types.h"
#define WIN_NAME "so_long"

int	check_map_format(char *str);
int	ft_strlen(const char *str);
int	print_error(char *str);
int  line_count(char *str);
char	*get_next_line(int fd);
int parse_map(t_map *map);
void    init(t_data *data, char *map_path);
void	load_map(t_map *map);
void	check_walls(t_map *map);
void check_map_elt(t_map *map);
void	init_map_sprites(t_data *data);
void	draw_bg(t_data *data);
void	draw_map(t_data *data);
void	draw_player(t_data *data);

#endif