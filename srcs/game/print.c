#include "cub3d.h"

void	vertical_line(t_game *game, t_render *render, t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->win_height)
	{
		x = -1;
		while (++x < game->win_width)
			data->addr[y * game->win_width + x] = render->buffer[y][x];
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, data->img, 0, 0);
}

void	cls(void)
{
	int			x;
	int			y;
	t_game		game;
	t_render	render;

	x = -1;
	while (++x < game.win_width)
	{
		y = -1;
		while (++y < game.win_height)
			render.buffer[x][y] = 0;
	}
}
