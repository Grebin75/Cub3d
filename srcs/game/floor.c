#include "cub3d.h"

void	floor_draw(t_game *game, t_render *render)
{
	int		y;
	int		position;
	float	raydirx0;
	float	raydirx1;
	float	raydiry0;
	float	raydiry1;
	float	vertical_camera;

	y = -1;
	while (++y < game->win_height)
	{
		raydirx0 = render->dir_x - render->plane_x;
		raydiry0 = render->dir_y - render->plane_y;
		raydirx1 = render->dir_x + render->plane_x;
		raydiry1 = render->dir_y + render->plane_y;
		position = y - game->win_height / 2;
		vertical_camera = 0.5 * game->win_height;
	}
}
