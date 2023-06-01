#include "cub3d.h"

static void	load_images(t_game *game)
{
	int	i;

	i = 64;
	game->img = malloc(sizeof(void *) * 3);
	if (!game->img)
		print_error("ERROR ON IMAGE MALLOC\n");
	game->img[0] = mlx_xpm_file_to_image(game->mlx, \
	"../imgs/floor.xpm", &i, &i);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, \
	"../imgs/wall.xpm", &i, &i);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, \
	"../imgs/char.xpm", &i, &i);
}

void	put_images(t_game *game, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	load_images(game);
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (cub->map[i][j] == 'N')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[2], i * 64, j * 64);
			}
		}
	}
}
