/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:11:21 by gade-alm          #+#    #+#             */
/*   Updated: 2023/07/25 12:44:58 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_konami(int keycode, t_game *game)
{
	static int	konami[10] = {65362, 65362, 65364, 65364, 65361, \
	65363, 65361, 65363, 98, 97};

	if (keycode == konami[game->code])
		game->code++;
	else
		game->code = 0;
	if (game->code == 10)
	{
		print_error("You WON the game using KONAMI CODE, congrats!");
		game->code = 0;
	}
}

int	close_keys(int keycode)
{
	check_konami(keycode, game());
	if (keycode == 65363 || keycode == 65361 || \
	keycode == 115 || keycode == 119 || keycode == 100 || keycode == 97)
		movement_keys(keycode);
	if (keycode == 65307)
		print_error("You closed the game");
	return (1);
}

int	button_exit(void)
{
	print_error("You closed the game");
	return (0);
}
