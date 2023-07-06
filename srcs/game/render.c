#include "cub3d.h"

static int	print_walls(int texture_y, int texture_x, int color)
{
	if (this()->map[render()->mapy][render()->mapx] == '1')
		color = game()->img[0][render()->img_height * texture_y + texture_x];
	else
		color = 0;
	return (color);
}

void	rendering(void)
{
	int		x;
	int		y;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_dist;
	int		hit;
	int		side;
	double	step;
	int		stepx;
	int		stepy;
	int		lineheight;
	int		draw_start;
	int		draw_end;
	int		color = 0;
	int		texture_number;
	double	wallx;
	int		texture_x;
	int		texture_y;
	double	texture_position;

	x = -1;
	while (++x < game()->win_width)
	{
		camerax = ((2 * x) / (double)(game()->win_width) - 1);
		raydirx = render()->dir_x + render()->plane_x * camerax;
		raydiry = render()->dir_y + render()->plane_y * camerax;
		render()->mapx = (int)render()->ply_x;
		render()->mapy = (int)render()->ply_y;
		render()->delta_x = fabs(1 / raydirx);
		render()->delta_y = fabs(1 / raydiry);
		hit = 0;
		if (raydirx < 0)
		{
			stepx = -1;
			side_dist_x = ((render()->ply_x - render()->mapx) * render()->delta_x);
		}
		else
		{
			stepx = 1;
			side_dist_x = ((render()->mapx + 1.0 - render()->ply_x) * render()->delta_x);
		}
		if (raydiry < 0)
		{
			stepy = -1;
			side_dist_y = ((render()->ply_y - render()->mapy) * render()->delta_y);
		}
		else
		{
			stepy = 1;
			side_dist_y = ((render()->mapy + 1.0 - render()->ply_y) * render()->delta_y);
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += render()->delta_x;
				render()->mapx += stepx;
				side = 0;
			}
			else
			{
				side_dist_y += render()->delta_y;
				render()->mapy += stepy;
				side = 1;
			}
			if (this()->map[render()->mapy][render()->mapx] == '1')
				hit = 1;
			if (side == 0)
				wall_dist = (render()->mapx - render()->ply_x + (1 - stepx) / 2) / raydirx;
			else
				wall_dist = (render()->mapy - render()->ply_y + (1 - stepy) / 2) / raydiry;
			lineheight = (int)(game()->win_height / wall_dist);
			draw_start = ((-lineheight / 2) + (game()->win_height / 2));
			if (draw_start < 0)
				draw_start = 0;
			draw_end = ((lineheight / 2) + (game()->win_height / 2));
			if (draw_end >= game()->win_height)
				draw_end = game()->win_height - 1;

			texture_number = this()->map[render()->mapy][render()->mapx] - '0';
			if (side == 0)
				wallx = render()->ply_y + wall_dist * raydiry;
			else
				wallx = render()->ply_x + wall_dist * raydirx;
			wallx -= floor(wallx);
			texture_x = (int)(wallx * (double)render()->img_width);
			if (side == 0 && raydirx > 0)
				texture_x = render()->img_width - texture_x - 1;
			if (side == 1 && raydiry < 0)
				texture_x = render()->img_width - texture_x - 1;
			step = 1.0 * render()->img_height / lineheight;
			texture_position = (draw_start - game()->win_height / 2 + lineheight / 2) * step;
			y = draw_start;
			while (y < draw_end)
			{
				texture_y = (int)texture_position & (render()->img_height - 1);
				texture_position += step;
				color = print_walls(texture_y, texture_x, color);
				render()->buffer[y][x] = color;
				y++;
			}
		}
	}

}



int	start_game(void)
{
	cls();
	rendering();
	vertical_line(game(), render(), data());
	return (0);
}
