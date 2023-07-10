#include "cub3d.h"

static int	print_walls(int texture_y, int texture_x, int text_number)
{
	int	color;

	if (this()->map[render()->mapy][render()->mapx] == '1')
		color = game()->img[text_number] \
		[render()->img_height * texture_y + texture_x];
	else
		color = 0;
	return (color);
}

void	textures_wall(t_render *render, t_game *game, int x)
{
	int	y;

	render->texture_x = (int)(render->wall_x * (double)render->img_width);
	if (render->side == 0 && render->ray_dirx > 0)
		render->texture_x = render->img_width - render->texture_x - 1;
	if (render->side == 1 && render->ray_diry < 0)
		render->texture_x = render->img_width - render->texture_x - 1;
	render->step = 1.0 * render->img_height / render->lineheight;
	render->texture_position = (render->draw_start - game->win_height / 2 + \
	render->lineheight / 2) * render->step;
	y = render->draw_start;
	while (y < render->draw_end)
	{
		render->texture_y = (int)render->texture_position & \
		(render->img_height - 1);
		render->texture_position += render->step;
		(render->buffer[y][x]) = print_walls(render->texture_y, \
		render->texture_x, render->texture_number);
		y++;
	}
}

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
