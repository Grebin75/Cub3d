#include "cub3d.h"


void	rendering(void)
{
	int		x;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_dist;
	int		hit;
	int		side;
	int		stepx;
	int		stepy;
	int		lineheight;
	int		draw_start;
	int		draw_end;
	int		color;

	x = -1;
	while (++x < game()->win_width)
	{
		camerax = ((2 * x) / (double)(game()->win_width) - 1);
		raydirx = render()->dir_x + render()->plane_x * camerax;
		raydiry = render()->dir_y + render()->plane_y * camerax;
		mapx = (int)render()->ply_x;
		mapy = (int)render()->ply_y;
		render()->delta_x = fabs(1 / raydirx);
		render()->delta_y = fabs(1 / raydiry);
		hit = 0;
		if (raydirx < 0)
		{
			stepx = -1;
			side_dist_x = ((render()->ply_x - mapx) * render()->delta_x);
		}
		else
		{
			stepx = 1;
			side_dist_x = ((mapx + 1.0 - render()->ply_x) * render()->delta_x);
		}
		if (raydiry < 0)
		{
			stepy = -1;
			side_dist_y = ((render()->ply_y - mapy) * render()->delta_y);
		}
		else
		{
			stepy = 1;
			side_dist_y = ((mapy + 1.0 - render()->ply_y) * render()->delta_y);
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += render()->delta_x;
				mapx += stepx;
				side = 0;
			}
			else
			{
				side_dist_y += render()->delta_y;
				mapy += stepy;
				side = 1;
			}
			if (this()->map[mapy][mapx] == '1')
				hit = 1;
			if (side == 0)
				wall_dist = (mapx - render()->ply_x + (1 - stepx) / 2) / raydirx;
			else
				wall_dist = (mapy - render()->ply_y + (1 - stepy) / 2) / raydiry;
			lineheight = (int)(game()->win_height / wall_dist);
			draw_start = ((-lineheight / 2) + (game()->win_height / 2));
			if (draw_start < 0)
				draw_start = 0;
			draw_end = ((lineheight / 2) + (game()->win_height / 2));
			if (draw_end >= game()->win_height)
				draw_end = game()->win_height - 1;
			if (this()->map[mapy][mapx] == '1')
				color = 0xFF0000;
			else
				color = 0x000000;
			if (side == 1)
				color /= 2;
			vertical_line(game(), x, draw_start, draw_end, color);
		}
	}
}

int	start_game(void)
{
	cls(game());
	rendering();
	return (0);
}