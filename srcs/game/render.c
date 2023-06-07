#include "cub3d.h"

void	render(t_cub *cub,t_game *game)
{
	int		i;
	double	camerax;
	double	raydirx;
	double	ray_diry;
	double	plane_x = 0;
	double	plane_y = 0.66;

	i = -1;
	while (++i < game->win_width)
	{
		camerax = 2 * x / (double)game->win_width - 1;
		raydirx = gane->dir_x + plane_x * camerax;
		raydiry = game->dir_y + plane_y * camerax;
	}
}
