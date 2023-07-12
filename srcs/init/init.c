#include <cub3d.h>

void	init_vars(t_game *game, t_render *render)
{
	game->win_width = 640;
	game->win_height = 480;
	render->img_height = 64;
	render->img_width = 64;
	render->dir_x = (-1 * (render->angle == 90)) + (render->angle == 270);
	render->dir_y = (-1 * (render->angle == 0)) + (render->angle == 180);
	render->plane_y = 0.66 * ((render->angle == 270)) + (render->angle == 90);
	render->plane_x = 0.66 * ((render->angle == 0)) + (render->angle == 180);
	render->hit = 0;
	render->mv_speed = 0.05;
	render->rt_speed = 0.05;
	render->neg_rt = -0.05;
	render->cpy_x = render->ply_x;
	render->cpy_y = render->ply_y;
	render->cpy_map_x = (int)render->ply_x;
	render->cpy_map_y = (int)render->ply_y;
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

t_render	*render(void)
{
	static t_render	render;

	return (&render);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}
