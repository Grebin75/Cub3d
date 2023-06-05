#include "cub3d.h"

int	movement_keys(int keycode)
{
	mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->img[0], \
	game()->ply_x, game()->ply_y);
	game()->ply_x += ((keycode == 100) - (keycode == 97)) * 64;
	game()->ply_y += ((keycode == 115) - (keycode == 119)) * 64;
	mlx_put_image_to_window(game()->mlx, game()->mlx_win, game()->img[2], game()->ply_x, game()->ply_y);
	print_line(game());
	return (0);
}

int	close_keys(int keycode)
{
	if (keycode == 97 || keycode == 100 || keycode == 115 || keycode == 119)
		movement_keys(keycode);
	if (keycode == 65307)
	{
		printf("You closed the game.\n");
		rm_cub(this());
	}
	return (1);
}

int	button_exit(void)
{
	printf("You closed the game.\n");
	rm_cub(this());
	return (0);
}

void	print_line(t_game *game)
{
	mlx_pixel_put(game->mlx, game->mlx_win, game->ply_x * 64, game->ply_y * 64, 0x00A01E02);
}
