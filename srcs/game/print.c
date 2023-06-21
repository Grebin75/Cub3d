#include "cub3d.h"

void	vertical_line(t_game *game, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	if (color == (0x000000))
		return ;
	while (y <= y2)
	{
		my_mlx_pixel_put(data(), x, y, color);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, data()->img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
			my_mlx_pixel_put(data(), x, y, 0x00000000);
	}
}
