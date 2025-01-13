/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:29:52 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/13 14:01:06 by srabeman         ###   ########.fr       */
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
size_t  line_count(char *str);
char	*get_next_line(int fd);
int parse_map(t_map *map);
void    init(t_data *data, char *map_path);

#endif