/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:52 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/16 09:08:45 by srabeman         ###   ########.fr       */
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
#include <stdbool.h>
#include "types.h"
#define WIN_NAME "so_long"
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

int	check_map_format(char *str);
int	on_destroy(t_data *data);
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
void check_player_position(t_data *data);
void	move_player(t_data *data, int move_x, int move_y);
int	handle_key(int keycode, t_data *data);
void free_map(char **map);
char **copy_map(char **map);
bool	validate_map(char **map, int start_x, int start_y, int collectibles_count);

#endif