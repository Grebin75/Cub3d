#include "cub3d.h"

static void	key_ws(t_render *render, int keycode)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = 0;
	tmp_y = 0;
	if (keycode == 119)
	{
		tmp_x = render->ply_x + render->dir_x * render->mv_speed;
		tmp_y = render->ply_y + render->dir_y * render->mv_speed;
	}
	if (keycode == 115)
	{
		tmp_x = render->ply_x - render->dir_x * render->mv_speed;
		tmp_y = render->ply_y - render->dir_y * render->mv_speed;
	}
	if (this()->map[(int)tmp_y][(int)tmp_x] != '1')
	{
		render->ply_x = tmp_x;
		render->ply_y = tmp_y;
	}
}

static void	key_ad(t_render *render, int keycode)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = 0;
	tmp_y = 0;
	if (keycode == 97)
	{
		tmp_x = render->ply_x + render->dir_x * render->mv_speed;
		tmp_y = render->ply_y + render->dir_y * render->mv_speed;
	}
	else if (keycode == 100)
	{
		tmp_x = render->ply_x - render->dir_x * render->mv_speed;
		tmp_y = render->ply_y - render->dir_y * render->mv_speed;
	}
	if (this()->map[(int)tmp_y][(int)tmp_x] != '1')
	{
		printf("%f\n%f\n", tmp_x, tmp_y);
		render->ply_x = tmp_x;
		render->ply_y = tmp_y;
	}
}

static void	rotate_left(t_render *render)
{
	double	old_dir;
	double	old_plane;

	old_dir = render->dir_x;
	render->dir_x = (render->dir_x * cos(-render->rt_speed)) \
	- (render->dir_y * sin(-render->rt_speed));
	render->dir_y = old_dir * sin(-render->rt_speed) \
	+ render->dir_y * cos(-render->rt_speed);
	old_plane = render->plane_x;
	render->plane_x = render->plane_x * cos(-render->rt_speed) \
	- render->plane_y * sin(-render->rt_speed);
	render->plane_y = old_plane * sin(-render->rt_speed) \
	+ render->plane_y * cos(-render->rt_speed);
}

static void	rotate_right(t_render *render)
{
	double	old_dir;
	double	old_plane;

	printf("TESTE\n");
	old_dir = render->dir_x;
	render->dir_x = render->dir_x * cos(render->rt_speed) \
	- render->dir_y * sin(render->rt_speed);
	render->dir_y = old_dir * sin(render->rt_speed) \
	+ render->dir_y * cos(render->rt_speed);
	old_plane = render->plane_x;
	render->plane_x = render->plane_x * cos(render->rt_speed) \
	- render->plane_y * sin(render->rt_speed);
	render->plane_y = old_plane * sin(render->rt_speed) \
	+ render->plane_y * cos(render->rt_speed);
}

int	movement_keys(int keycode)
{
	if (keycode == 119 || keycode == 115)
		key_ws(render(), keycode);
	if (keycode == 97 || keycode == 100)
		key_ad(render(), keycode);
	if (keycode == 65363)
		rotate_right (render());
	if (keycode == 65361)
		rotate_left (render());
	return (0);
}

int	close_keys(int keycode)
{
	if (keycode == 65363 || keycode == 65361 || \
	keycode == 115 || keycode == 119 || keycode == 100 || keycode == 97)
		movement_keys(keycode);
	if (keycode == 65307)
	{
		printf("You closed the game.\n");
		rm_cub(this());
	}
	return (1);
}

int	button_exit(void)
{
	printf("You closed the game.\n");
	rm_cub(this());
	return (0);
}
