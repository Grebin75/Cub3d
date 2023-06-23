#include "cub3d.h"

static void	key_ws(t_render *render, int keycode)
{
	if (keycode == 119)
	{
		if (this()->map[(int)(render->ply_y + render->dir_x \
		* render->mv_speed)][(int)render->ply_x] != '1')
			render->ply_x += render->dir_x * render->mv_speed;
		if (this()->map[(int)render->ply_y][(int)(render->ply_x \
		+ render->dir_y * render->mv_speed)] != '1')
			render->ply_y += render->dir_y * render->mv_speed;
	}
	if (keycode == 115)
	{
		if (this()->map[(int)(render->ply_y - render->dir_x \
		* render->mv_speed)][(int)render->ply_x] != '1')
			render->ply_x -= render->dir_x * render->mv_speed;
		if (this()->map[(int)render->ply_y][(int)(render->ply_x \
		- render->dir_y * render->mv_speed)] != '1')
			render->ply_y -= render->dir_y * render->mv_speed;
	}
}

static void	key_ad(t_render *render, int keycode)
{
	if (keycode == 97)
	{
		if (this()->map[(int)render->ply_y][(int)(render->ply_x \
		- render->dir_y * render->mv_speed)] != '1')
			render->ply_x -= render->dir_y * render->mv_speed;
	}
	if (keycode == 100)
	{
		if (this()->map[(int)render->ply_y][(int)(render->ply_x \
		+ render->dir_y * render->mv_speed)] != '1')
			render->ply_x += render->dir_y * render->mv_speed;
	}
}

static void	rotate(t_render *render, int keycode)
{
	double	old_dir;
	double	old_plane;

	if (keycode == 65363)
	{
		old_dir = render->dir_x;
		render->dir_x = (render->dir_x * cos(render->neg_rt)) \
		- (render->dir_y * sin(render->neg_rt));
		render->dir_y = old_dir * sin(render->neg_rt) \
		+ render->dir_y * cos(render->neg_rt);
		old_plane = render->plane_x;
		render->plane_x = render->plane_x * cos(render->neg_rt) \
		- render->plane_y * sin(render->neg_rt);
		render->plane_y = old_plane * sin(render->neg_rt) \
		+ render->plane_y * cos(render->neg_rt);
	}
	else if (keycode == 65361)
	{
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
}

int	movement_keys(int keycode)
{
	if (keycode == 119 || keycode == 115)
		key_ws(render(), keycode);
	if (keycode == 97 || keycode == 100)
		key_ad(render(), keycode);
	if (keycode == 65363 || keycode == 65361)
		rotate (render(), keycode);
	return (0);
}

int	close_keys(int keycode)
{
	printf("%i\n", keycode);
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
