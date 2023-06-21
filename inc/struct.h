/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:42:36 by grebin            #+#    #+#             */
/*   Updated: 2023/06/21 10:22:07 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"

typedef struct s_cub	t_cub;
typedef struct s_game	t_game;
typedef struct s_data	t_data;
typedef struct s_view	t_view;
typedef struct s_render	t_render;

struct s_cub{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor;
	char	*ceiling;
	char	**map;
	int		f_rgb;
	int		c_rgb;
};

struct s_game{
	void	**img;
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	int		height;
};

struct s_view{
	int		w_view;
	int		e_view;
	int		n_view;
	int		s_view;
};

struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct	s_render{
	double	ply_x;
	double	ply_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mv_speed;
	double	rt_speed;
	double	neg_rt;
	double	time;
	double	old_time;
	double	camera_x;
	double	ray_dirx;
	double	ray_diry;
	int		map_x;
	int		map_y;
	double	side_dist_y;
	double	side_dist_x;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
};

t_cub		*this(void);
void		print_cub(t_cub *cub);
void		rm_cub(t_cub *cub);
void		print_error(char *s);
t_game		*game(void);
t_render	*render(void);
t_data		*data(void);
void		init_vars(t_game *game, t_render *render);

#endif