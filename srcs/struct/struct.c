/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:44:00 by grebin            #+#    #+#             */
/*   Updated: 2023/07/20 13:10:52 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *s)
{
	write(2, s, ft_strlen(s));
	rm_cub(this(), game());
}

static void	rm_game(t_game *game, t_data *data)
{
	int	i;

	i = 0;
	if (game->img)
	{
		while (i < 4)
			free(game->img[i++]);
		free(game->img);
	}
	if (data->img)
		mlx_destroy_image(game->mlx, data->img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free (game->mlx);
	}
}

void	rm_cub(t_cub *cub, t_game *game)
{
	rm_game(game, data());
	if (cub->no_texture)
		free(cub->no_texture);
	if (cub->so_texture)
		free(cub->so_texture);
	if (cub->we_texture)
		free(cub->we_texture);
	if (cub->ea_texture)
		free(cub->ea_texture);
	if (cub->floor)
		free(cub->floor);
	if (cub->ceiling)
		free(cub->ceiling);
	if (cub->map)
		free_matrix(cub->map);
	exit (0);
}

void	print_cub(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->no_texture)
		printf("NORTH: %s\n", cub->no_texture);
	if (cub->so_texture)
		printf("SOUTH: %s\n", cub->so_texture);
	if (cub->we_texture)
		printf("WEST: %s\n", cub->we_texture);
	if (cub->ea_texture)
		printf("EAST: %s\n", cub->ea_texture);
	if (cub->floor)
		printf("FLOOR: %s\n", cub->floor);
	if (cub->ceiling)
		printf("CEILING: %s\n", cub->ceiling);
	printf("MAP:\n");
	while (cub->map && cub->map[++i])
		printf("%s\n", cub->map[i]);
}

t_cub	*this(void)
{
	static t_cub	cub;

	return (&cub);
}
