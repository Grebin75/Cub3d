/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:11:21 by gade-alm          #+#    #+#             */
/*   Updated: 2023/07/20 13:11:21 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_keys(int keycode)
{
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
