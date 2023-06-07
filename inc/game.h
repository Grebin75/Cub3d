#ifndef GAME_H
# define GAME_H

# include "struct.h"

void	render(t_cub *cub, t_game *game);
int		close_keys(int keycode);
int		button_exit(void);
int		movement_keys(int keycode);

#endif