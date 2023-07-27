/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:10:01 by gade-alm          #+#    #+#             */
/*   Updated: 2023/07/27 09:43:47 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		print_error("Error:\nWrong number of arguments\n");
	start_engine(av);
	mlx_loop_hook(game()->mlx, &start_game, &game);
	mlx_hook(game()->mlx_win, 02, (1L << 0), close_keys, game);
	mlx_hook(game()->mlx_win, 17, (1L << 2), button_exit, game);
	mlx_loop(game()->mlx);
}
