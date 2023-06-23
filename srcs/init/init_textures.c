#include "cub3d.h"

void	init_textures(t_cub *cub,t_game *game)
{
	int	width;
	int	height;

	width = 64;
	height = width;
	game->img = malloc(sizeof(void *) * 4);
	if (!game->img)
		print_error("Imgs malloc error");
	game->img[0] = mlx_xpm_file_to_image(game->mlx, cub->no_texture, &width, &height);
	if (!game->img[0])
		print_error("Error on image");
	game->img[1] = mlx_xpm_file_to_image(game->mlx, cub->so_texture, &width, &height);
	if (!game->img[1])
		print_error("Error on image");
	game->img[2] = mlx_xpm_file_to_image(game->mlx, cub->we_texture, &width, &height);
	if (!game->img[2])
		print_error("Error on image");
	game->img[3] = mlx_xpm_file_to_image(game->mlx, cub->ea_texture, &width, &height);
	if (!game->img[3])
		print_error("Error on image");
}