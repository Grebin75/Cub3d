#include "cub3d.h"

void	rendering(void)
{
	int		i;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;

	i = -1;
	while (++i < game()->win_width)
	{
		render()->camera_x = 2 * i / (double)game()->win_width - 1;
		render()->ray_dirx = render()->dir_x + render()->plane_x * render()->camera_x;
		render()->ray_diry = render()->dir_y + render()->plane_y * render()->camera_x;
		render()->map_x = (int)render()->ply_x;
		render()->map_y = (int)render()->ply_y;
		render()->delta_x = fabs(1 / render()->ray_dirx);
		render()->delta_y = fabs(1 / render()->ray_diry);

		render()->hit = 0;
		if (render()->ray_dirx < 0)
		{
			render()->step_x = -1;
			render()->side_dist_x = (render()->ply_x - render()->map_x) * render()->delta_x;
		}
		else
		{
			render()->step_x = 1;
			render()->side_dist_x = (render()->map_x + 1.0 - render()->ply_x) * render()->delta_x;
		}
		if (render()->ray_diry < 0)
		{
			render()->step_y = -1;
			render()->side_dist_y = (render()->ply_y - render()->map_y) * render()->delta_y;
		}
		else
		{
			render()->step_y = 1;
			render()->side_dist_y = (render()->map_y + 1.0 - render()->ply_y) * render()->delta_y;
		}
		while (render()->hit == 0)
		{
			if (render()->side_dist_x < render()->side_dist_y)
			{
				render()->side_dist_x += render()->delta_x;
				render()->map_x += render()->step_x;
				render()->side = 0;
			}
			else
			{
				render()->side_dist_y += render()->delta_y;
				render()->map_y += render()->step_y;
				render()->side = 1;
			}
			if (this()->map[render()->map_x][render()->map_y] > 0)
				render()->hit = 1;
		}
		if (render()->side == 0)
			render()->wall_dist = render()->map_x - render()->ply_x + ((1 - render()->step_x) / 2) - render()->ray_dirx;
		else
			render()->wall_dist = render()->map_y - render()->ply_y + ((1 - render()->step_y) / 2) - render()->ray_diry;
		line_height = (int)(game()->win_height / render()->wall_dist);
		draw_start = ((line_height * -1) / 2) + (game()->win_height / 2);
		if (draw_start < 0)
			draw_start = 0;
		draw_end = (line_height / 2) + (game()->win_height / 2);
		if (draw_end >= game()->win_height)
			draw_end = game()->win_height - 1;
		if (this()->map[render()->map_x / 64][render()->map_y / 64] == 1)
			color = 0xFF0000;
		else
			color = 0x00FF00;
		if (render()->side == 1)
			color /= 2;
		vertical_line(game(), i, draw_start, draw_end, color);
	}
}

int	start_game(void)
{
	rendering();
	// cls(game());
	return (0);
}