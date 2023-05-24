#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Wrong number of arguments");
		return (0);
	}
	parse_main(av);
	// game()->mlx = mlx_init();
	// (game()->mlx_win) = mlx_new_window((game()->mlx), (game()->height), \
	// (game()->width), "cub3d");
	// mlx_loop(game()->mlx);
}
