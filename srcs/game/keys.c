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
	int		side;

	if (render->angle == 270 || render->angle == 0)
		side = -1;
	else
		side = 1;
	tmp_x = 0;
	tmp_y = 0;
	if (keycode == 97)
	{
		tmp_x = render->ply_x - render->dir_y * render->mv_speed * side;
		tmp_y = render->ply_y + render->dir_x * render->mv_speed * side;
	}
	else if (keycode == 100)
	{
		tmp_x = render->ply_x + render->dir_y * render->mv_speed * side;
		tmp_y = render->ply_y - render->dir_x * render->mv_speed * side;
	}
	if (this()->map[(int)tmp_y][(int)tmp_x] != '1')
	{
		render->ply_x = tmp_x;
		render->ply_y = tmp_y;
	}
}

static void	rotate_a(t_render *render)
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

static void	rotate_d(t_render *render)
{
	double	old_dir;
	double	old_plane;

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
	if (render()->angle == 180 || render()->angle == 90)
	{
		if (keycode == 65361)
			rotate_d (render());
		else if (keycode == 65363)
			rotate_a (render());
	}
	else if (render()->angle == 0 || render()->angle == 270)
	{
		if (keycode == 65361)
			rotate_a (render());
		else if (keycode == 65363)
			rotate_d (render());
	}
	return (0);
}
