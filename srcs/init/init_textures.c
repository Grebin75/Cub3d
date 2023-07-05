#include "cub3d.h"

static void	load_images(int *text, char *path, t_render *render, t_game *game)
{
	int	x;
	int	y;

	(data()->img) = mlx_xpm_file_to_image(game->mlx, path, &render->img_width, \
	&render->img_height);
	(data()->addr) = (int *)mlx_get_data_addr(data()->img, \
	&data()->bits_per_pixel, &data()->line_length, &data()->endian);
	x = -1;
	while (++x < render->img_height)
	{
		y = -1;
		while (++y < render->img_width)
			text[render->img_width * x + y] = data()->addr[render->img_width * x + y];
	}
	mlx_destroy_image(game->mlx, data()->img);
}

void	init_textures(t_cub *cub, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->img = (int **)malloc(sizeof(int *) * 4);
	while (++i < 4)
	{
		game->img[i] = malloc(sizeof(int) * (render()->img_height * \
		render()->img_width));
		if (!game->img[i])
			print_error("Error on Init Textures");
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < render()->img_width * render()->img_height)
			game->img[i][j] = 0;
	}
	load_images(game->img[0], cub->no_texture, render(), game);
	load_images(game->img[1], cub->so_texture, render(), game);
	load_images(game->img[2], cub->ea_texture, render(), game);
	load_images(game->img[3], cub->we_texture, render(), game);
}
