/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:18:49 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/14 14:04:05 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_map
{
	char		*path;
	int		map_height;
	int		map_width;
	int			fd;
	char		**map;
	int		collectibles;
	int		exit;
	int		start;
	int		moves;
} 			t_map;

typedef	struct	s_sprite
{
	int	sprite_w;
	int	sprite_h;
	void	*img;
}			t_sprite;

typedef struct	s_position
{
	int	pos_x;
	int	pos_y;
}		t_position;

typedef struct s_player
{
	t_position	position;
	t_position	start_position;
	t_sprite	sprite;
}	t_player;

typedef	struct	s_data
{
    void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*mlx_addr;
	t_sprite	wall_sprite;
	t_sprite	exit_sprite;
	t_sprite	start_sprite;
	t_sprite	collectible_sprite;
	t_sprite	floor_sprite;
	t_player	player;
	int		bppx;
	int		size_line;
	int		endian;
	short int	is_winning;
	t_map	map;
}			t_data;


typedef	struct s_tile
{
	int	value;
	char	elt;
}	t_tile;


#endif