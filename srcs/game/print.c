#include "cub3d.h"

static void	floor_ceiling(t_render *render, int x, int y)
{
	if (this()->map[render->mapy][render->mapx] \
	!= '1' && y < game()->win_height / 2)
		render->buffer[y][x] = render->ceiling_text;
	else if (this()->map[render->mapy][render->mapx] \
	!= '1' && y < game()->win_height * 2)
		render->buffer[y][x] = render->floor_text;
}

static void	print_walls(t_render *render, int x, int y)
{
	if (render->side == 0 && \
	this()->map[render->mapy][render->mapx] == '1')
	{
		if (render->mapx < render->ply_x)
			render->buffer[y][x] = game()->img[3] \
			[render->img_height * render->texture_y + render->texture_x];
		else
			render->buffer[y][x] = game()->img[2] \
			[render->img_height * render->texture_y + render->texture_x];
	}
	else if (render->side == 1 && this()->map[render->mapy][render->mapx] == '1')
	{
		if (render->mapy < render->ply_y)
			render->buffer[y][x] = game()->img[0] \
			[render->img_height * render->texture_y + render->texture_x];
		else
			render->buffer[y][x] = game()->img[1] \
			[render->img_height * render->texture_y + render->texture_x];
	}
}

void	textures_wall(t_render *render, t_game *game, int x)
{
	int	y;

	render->texture_x = (int)(render->wall_x * render->img_width);
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
		print_walls(render, x, y);
		y++;
		floor_ceiling(render, x, y);

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
	for(int y = 0; y < game->win_height; y++) 
	{
		for(int x = 0; x < game->win_width; x++) 
		{
			render->buffer[y][x] = 0;
		}
	}
}

void	cls(void)
{
	int			x;
	int			y;

	y = -1;
	while (++y < game()->win_height)
	{
		x = -1;
		while (++x < game()->win_width)
		{
			data()->addr[y * game()->win_width + x] = 0x000000;
		}
	}
	// mlx_put_image_to_window(game()->mlx, game()->mlx_win, data()->img, 0, 0);
}
