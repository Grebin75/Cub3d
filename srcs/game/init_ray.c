#include "cub3d.h"

static void	init_dda_calc(t_render *render)
{
	if (render->ray_dirx < 0)
	{
		render->stepx = -1;
		render->side_dist_x = ((render->ply_x - render->mapx) \
		* render->delta_x);
	}
	else
	{
		render->stepx = 1;
		render->side_dist_x = ((render->mapx + 1.0 - render->ply_x) \
		* render->delta_x);
	}
	if (render->ray_diry < 0)
	{
		render->stepy = -1;
		render->side_dist_y = ((render->ply_y - render->mapy) \
		* render->delta_y);
	}
	else
	{
		render->stepy = 1;
		render->side_dist_y = ((render->mapy + 1.0 - render->ply_y) \
		* render->delta_y);
	}
}

void	init_ray(t_render *render, t_game *game, int x)
{
	render->cam_x = ((2 * x) / (double)(game->win_height) - 1);
	render->ray_dirx = render->dir_x + render->plane_x * render->cam_x;
	render->ray_diry = render->dir_y + render->plane_y * render->cam_x;
	render->mapx = (int)render->ply_x;
	render->mapy = (int)render->ply_y;
	render->delta_x = fabs(1 / render->ray_dirx);
	render->delta_y = fabs(1 / render->ray_diry);
	init_dda_calc(render);
}

void	find_hit_wall(t_render *render, t_cub *cub)
{
	if (render->side_dist_x < render->side_dist_y)
	{
		render->side_dist_x += render->delta_x;
		render->mapx += render->stepx;
		render->side = 0;
	}
	else
	{
		render->side_dist_y += render->delta_y;
		render->mapy += render->stepy;
		render->side = 1;
	}
	if (cub->map[render->mapy][render->mapx] == '1')
		render->hit = 1;
}

void	draw_size(t_render *render, t_game *game)
{
	if (render->side == 0)
		render->wall_dist = (render->mapx - render->ply_x + (\
		1 - render->stepx) / 2) / render->ray_dirx;
	else
		render->wall_dist = (render->mapy - render->ply_y + \
		(1 - render->stepy) / 2) / render->ray_diry;
	render->lineheight = (int)(game->win_height / render->wall_dist);
	render->draw_start = ((-render->lineheight / 2) + (game->win_height / 2));
	if (render->draw_start < 0)
		render->draw_start = 0;
	render->draw_end = ((render->lineheight / 2) + (game->win_height / 2));
	if (render->draw_end >= game->win_height)
		render->draw_end = game->win_height - 1;
}
