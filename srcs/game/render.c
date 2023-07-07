#include "cub3d.h"

static int	print_walls(int texture_y, int texture_x)
{
	int	color;

	color = 0;
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
	double	step;
	double	wallx;
	int		texture_x;
	int		texture_y;
	double	texture_position;

	x = -1;
	while (++x < game()->win_width)
	{
		init_ray(render(), game(), x);
		render()->hit = 0;
		while (render()->hit == 0)
		{
			find_hit_wall(render(), this());
			draw_size(render(), game());
			if (render()->side == 0)
				wallx = render()->ply_y + render()->wall_dist * render()->ray_diry;
			else
				wallx = render()->ply_x + render()->wall_dist * render()->ray_dirx;
			wallx -= floor(wallx);
			texture_x = (int)(wallx * (double)render()->img_width);
			if (render()->side == 0 && render()->ray_dirx > 0)
				texture_x = render()->img_width - texture_x - 1;
			if (render()->side == 1 && render()->ray_diry < 0)
				texture_x = render()->img_width - texture_x - 1;
			step = 1.0 * render()->img_height / render()->lineheight;
			texture_position = (render()->draw_start - game()->win_height / 2 + render()->lineheight / 2) * step;
			y = render()->draw_start;
			while (y < render()->draw_end)
			{
				texture_y = (int)texture_position & (render()->img_height - 1);
				texture_position += step;
				(render()->buffer[y][x]) = print_walls(texture_y, texture_x);
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
