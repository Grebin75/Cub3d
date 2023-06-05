#include "cub3d.h"

void	put_images(t_game *game, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (cub->map[i][j] == 'N')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[2], j * 64, i * 64);
				game->ply_x = j * 64;
				game->ply_y = i * 64;
			}
			if (cub->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[1], j * 64, i * 64);
			if (cub->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0], j * 64, i * 64);
		}
	}
}
