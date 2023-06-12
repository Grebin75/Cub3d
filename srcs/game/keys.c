#include "cub3d.h"

int	movement_keys(int keycode)
{
	render()->ply_x += ((keycode == 100) - (keycode == 97)) * 64;
	render()->ply_y += ((keycode == 115) - (keycode == 119)) * 64;

	return (0);
}

int	close_keys(int keycode)
{
	// if (keycode == 97 || keycode == 100 || keycode == 115 || keycode == 119)
	// 	movement_keys(keycode);
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
