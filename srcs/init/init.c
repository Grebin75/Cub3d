#include <cub3d.h>

void	init_vars(t_game *game)
{
	game->win_width = 640;
	game->win_height = 480;
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}
