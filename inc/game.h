#ifndef GAME_H
# define GAME_H

# include "struct.h"

void		rendering(void);
int			close_keys(int keycode);
int			button_exit(void);
int			movement_keys(int keycode);
t_render	*render(void);
void		vertical_line(t_game *game, int x, int y1, int y2, int color);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			start_game(void);
void		cls(t_game *game);

#endif