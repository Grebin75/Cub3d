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
void		cls(void);
void		start_engine(char **av);
void		draw_size(t_render *render, t_game *game);
void		init_ray(t_render *render, t_game *game, int x);
void		find_hit_wall(t_render *render, t_cub *cub);
void		save_draw_numbers(t_render *render);
void		textures_wall(t_render *render, t_game *game, int x);
void		define_colors(t_render *render);

#endif