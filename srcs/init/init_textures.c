#include "cub3d.h"

static void	load_images(char *text, char *path, t_render *render, t_game *game)
{
	text = mlx_xpm_file_to_image(game->mlx, path, &render->img_width, \
	&render->img_height);
	if (!text)
		print_error("Error on load images");
}

void	init_textures(t_cub *cub, t_game *game)
{
	game->img = malloc(sizeof(void *) * 4);
	load_images(game->img[0], cub->no_texture, render(), game);
	load_images(game->img[1], cub->no_texture, render(), game);
	load_images(game->img[2], cub->no_texture, render(), game);
	load_images(game->img[3], cub->no_texture, render(), game);
}
