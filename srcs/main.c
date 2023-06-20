#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Wrong number of arguments");
		return (0);
	}
	parse_main(av);
	game()->mlx = mlx_init();
	init_vars(game(), render());
	(game()->mlx_win) = mlx_new_window((game()->mlx), (game()->win_width), \
	(game()->win_height), "cub3d");
	mlx_loop_hook(game()->mlx, &start_game, &game);

	mlx_hook(game()->mlx_win, 02, (1L << 0), close_keys, game);
	mlx_hook(game()->mlx_win, 17, (1L << 2), button_exit, game);
	mlx_loop(game()->mlx);
}
