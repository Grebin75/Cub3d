#include <cub3d.h>

void	init_vars(t_game *game)
{
	game->win_width = 640;
	game->win_height = 480;
	game->dir_x = -1;
	game->dir_y = 0;
	game->ply_x = 14;
	game->ply_y = 2;
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}
