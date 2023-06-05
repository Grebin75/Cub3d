#ifndef GAME_H
# define GAME_H

#include "struct.h"

int		close_keys(int keycode);
int		button_exit(void);
void	put_images(t_game *game, t_cub *cub);
void	load_images(t_game *game);
int		movement_keys(int keycode);
void	print_line(t_game *game);

#endif