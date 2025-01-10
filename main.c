/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabeman <srabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:21 by srabeman          #+#    #+#             */
/*   Updated: 2025/01/10 12:58:48 by srabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int main(void)
{
    void	*mlx_ptr;
    void	*mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "Hello so_long 42");
	mlx_loop(mlx_ptr);
}