/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:10:16 by gade-alm          #+#    #+#             */
/*   Updated: 2023/07/20 13:17:51 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_engine(char **av)
{
	parse_main(av);
	game()->mlx = mlx_init();
	init_vars(game(), render());
	init_textures(this(), game());
	(game()->mlx_win) = mlx_new_window((game()->mlx), (game()->win_width), \
	(game()->win_height), "cub3d");
	(data()->img) = mlx_new_image(game()->mlx, game()->win_width, \
	game()->win_height);
	(data()->addr) = (int *)mlx_get_data_addr(data()->img, \
	&data()->bits_per_pixel, &data()->line_length, &data()->endian);
}
