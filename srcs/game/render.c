#include "cub3d.h"

void	rendering(void)
{
	int		x;

	x = -1;
	while (++x < game()->win_width)
	{
		init_ray(render(), game(), x);
		render()->hit = 0;
		while (render()->hit == 0)
			find_hit_wall(render(), this());
		draw_size(render(), game());
		save_draw_numbers(render());
		textures_wall(render(), game(), x);
	}
}

int	start_game(void)
{
	cls();
	rendering();
	vertical_line(game(), render(), data());
	return (0);
}
