#include <cub3d.h>

void	init_vars(t_game *game, t_render *render)
{
	game->win_width = 640;
	game->win_height = 480;
	render->dir_x = -1;
	render->dir_y = 0;
	render->plane_x = 0;
	render->plane_y = 0.66;
	render->time = 0;
	render->old_time = 0;
	render->hit = 0;
	render->mv_speed = 0.05;
	render->rt_speed = 0.05;
	render->neg_rt = -0.05;
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
