#include "cub3d.h"

void	vertical_line(t_game *game, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	if (color == (0x000000))
		return ;
	while (y <= y2)
	{
		my_mlx_pixel_put(render(), x, y, color);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, data()->img, 0, 0);
}

void	my_mlx_pixel_put(t_render *render, int x, int y, int color)
{
	char	*dst;

	dst = render->image->data + (y * render->image->size_line + x * \
	(render->image->bpp / 8));
	*(unsigned int *)dst = color;
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
			my_mlx_pixel_put(render(), x, y, 0x00000000);
	}
}
