#include "cub3d.h"

void	vertical_line(t_game *game, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x, y, color);
		y++;
	}
}

void	cls(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->win_width)
	{
		y = -1;
		while (++y < game->win_height)
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x00000000);
	}
}
