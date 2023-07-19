#include "cub3d.h"

int	close_keys(int keycode)
{
	if (keycode == 65363 || keycode == 65361 || \
	keycode == 115 || keycode == 119 || keycode == 100 || keycode == 97)
		movement_keys(keycode);
	if (keycode == 65307)
	{
		printf("You closed the game.\n");
		rm_cub(this(), game());
	}
	return (1);
}

int	button_exit(void)
{
	printf("You closed the game.\n");
	rm_cub(this(), game());
	return (0);
}
