#ifndef GAME_H
# define GAME_H

# include "struct.h"

void		rendering(void);
int			close_keys(int keycode);
int			button_exit(void);
int			movement_keys(int keycode);
t_render	*render(void);
void		vertical_line(t_game *game, t_render *render, t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			start_game(void);
void		cls(t_game *game);
void		start_engine(char **av);

#endif