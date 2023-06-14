#include "cub3d.h"

int	movement_keys(int keycode)
{
	double	old_dir;
	double	old_plane;
	if (keycode == 119)
	{
		if ((this()->map[(int)(render()->ply_x + render()->dir_x * render()->mv_speed)]\
		[(int)render()->ply_y]) == 0)
			render()->ply_x += render()->dir_x * render()->mv_speed;
		if ((this()->map[(int)render()->ply_x][(int)(render()->ply_y + render()->dir_y *
		render()->mv_speed)]) == 0)
			render()->ply_y += render()->dir_y * render()->mv_speed;
	}
	if (keycode == 115)
	{
		if ((this()->map[(int)(render()->ply_x + render()->dir_x * render()->mv_speed)]\
		[(int)render()->ply_y]) == 0)
			render()->ply_x -= render()->dir_x * render()->mv_speed;
		if ((this()->map[(int)render()->ply_x][(int)(render()->ply_y + render()->dir_y *
		render()->mv_speed)]) == 0)
			render()->ply_y -= render()->dir_y * render()->mv_speed;
	}
	if (keycode == 100)
	{
		old_dir = render()->dir_x;
		render()->dir_x = render()->dir_x * cos(-render()->rt_speed) - render()->dir_y * sin(-render()->rt_speed);
		render()->dir_y = old_dir * sin(-render()->rt_speed) + render()->dir_y * cos(-render()->rt_speed);
		old_plane = render()->plane_x;
		render()->plane_x = render()->plane_x * cos(-render()->rt_speed) - render()->plane_y * sin(-render()->rt_speed);
		render()->plane_y = old_plane * sin(-render()->rt_speed) + render()->plane_y * cos(-render()->rt_speed);
	}
	if (keycode == 97)
	{
		old_dir = render()->dir_x;
		render()->dir_x = render()->dir_x * cos(render()->rt_speed) - render()->dir_y * sin(render()->rt_speed);
		render()->dir_y = old_dir * sin(-render()->rt_speed) + render()->dir_y * cos(render()->rt_speed);
		old_plane = render()->plane_x;
		render()->plane_x = render()->plane_x * cos(render()->rt_speed) - render()->plane_y * sin(render()->rt_speed);
		render()->plane_y = old_plane * sin(render()->rt_speed) + render()->plane_y * cos(render()->rt_speed);
	}
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
