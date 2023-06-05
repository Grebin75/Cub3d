#include <cub3d.h>

void	load_images(t_game *game)
{
	int	i;

	i = 64;
	game->img = malloc(sizeof(void *) * 3);
	if (!game->img)
		print_error("ERROR ON IMAGE MALLOC\n");
	game->img[0] = mlx_xpm_file_to_image(game->mlx, \
	"imgs/floor.xpm", &i, &i);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, \
	"imgs/wall.xpm", &i, &i);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, \
	"imgs/char.xpm", &i, &i);
}

void	init_vars(t_game *game)
{
	int	i;
	int	j;
	i = -1;
	load_images(game);
	while (this()->map[++i])
		;
	j = -1;
	while (this()->map[0][++j])
		;
	game->win_width = j * 64;
	game->win_height = i * 64;
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}
