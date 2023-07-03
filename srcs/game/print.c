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

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = (int*)data->addr + (y * data->line_length + x * \
// 	(data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	cls(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->win_width)
	{
		y = -1;
		while (++y < game->win_height)
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x000000);
	}
}
