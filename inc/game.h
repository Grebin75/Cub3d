#ifndef GAME_H
# define GAME_H

#include "struct.h"

int		close_keys(int keycode, t_game *game);
int		button_exit(void);
void	put_images(t_game *game, t_cub *cub);

#endif