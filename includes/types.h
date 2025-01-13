/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:18:49 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/13 11:24:22 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_map
{
	char		*path;
	size_t		map_height;
	size_t		map_width;
	int			fd;
	char		**grid;
	char		*tiles;
} 			t_map;

typedef	struct	s_data
{
    void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*mlx_addr;
	int		bppx;
	int		size_line;
	int		endian;

	t_map	map;
}			t_data;

typedef struct	s_position
{
	size_t	pos_x;
	size_t	pos_y;
}		t_position;


#endif