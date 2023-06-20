#include "cub3d.h"

static void	key_ws(t_render *render, int keycode)
{
	if (keycode == 119)
	{
		if (this()->map[(int)(render->ply_x + render->dir_x \
		* render->mv_speed)][(int)render->ply_y] != '1')
			render->ply_x += render->dir_x * render->mv_speed;
		if (this()->map[(int)render->ply_x][(int)(render->ply_y \
		+ render->dir_y * render->mv_speed)] != '1')
			render->ply_y += render->dir_y * render->mv_speed;
	}
	if (keycode == 115)
	{
		if (this()->map[(int)(render->ply_x - render->dir_x \
		* render->mv_speed)][(int)render->ply_y] != '1')
			render->ply_x -= render->dir_x * render->mv_speed;
		if (this()->map[(int)render->ply_x][(int)(render->ply_y \
		- render->dir_y * render->mv_speed)] != '1')
			render->ply_y -= render->dir_y * render->mv_speed;
	}
}

int	movement_keys(int keycode)
{
	double	old_dirX;
	double	old_dirY;
	double	old_planeX;
	double	old_planeY;

	if (keycode == 119 || keycode == 115)
		key_ws(render(), keycode);
	if (keycode == 100)
	{
		old_dirX = render()->dir_x;
		render()->dir_x = (render()->dir_x * cos(render()->neg_rt)) - (render()->dir_y * sin(render()->neg_rt));
		render()->dir_y = old_dirX * sin(render()->neg_rt) + render()->dir_y * cos(render()->neg_rt);
		old_planeX = render()->plane_x;
		render()->plane_x = render()->plane_x * cos(render()->neg_rt) - render()->plane_y * sin(render()->neg_rt);
		render()->plane_y = old_planeX * sin(render()->neg_rt) + render()->plane_y * cos(render()->neg_rt);
	}
	else if (keycode == 97)
	{
		old_dirY = render()->dir_x;
		render()->dir_x = render()->dir_x * cos(render()->rt_speed) - render()->dir_y * sin(render()->rt_speed);
		render()->dir_y = old_dirY * sin(render()->rt_speed) + render()->dir_y * cos(render()->rt_speed);
		old_planeY = render()->plane_x;
		render()->plane_x = render()->plane_x * cos(render()->rt_speed) - render()->plane_y * sin(render()->rt_speed);
		render()->plane_y = old_planeY * sin(render()->rt_speed) + render()->plane_y * cos(render()->rt_speed);
	}
	cls(game());
	return (0);
}

int	close_keys(int keycode)
{
	if (keycode == 97 || keycode == 100 || keycode == 115 || keycode == 119)
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
