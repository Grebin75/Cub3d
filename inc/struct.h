/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:42:36 by grebin            #+#    #+#             */
/*   Updated: 2023/07/18 09:53:56 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx_int.h"
# include "utils.h"

# define GAME_WIDTH 640
# define GAME_HEIGHT 480
# define PI 3.14159265359

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
	int		**img;
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
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct	s_render{
	int		x;
	double	cam_x;
	double	ply_x;
	double	ply_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	side_dist_x;
	double	side_dist_y;
	int		angle;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		mapy;
	int		mapx;
	double	mv_speed;
	double	rt_speed;
	double	neg_rt;
	double	ray_dirx;
	double	ray_diry;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	int		lineheight;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		texture_x;
	int		texture_y;
	double	step;
	double	texture_position;
	int		img_height;
	int		img_width;
	int		buffer[GAME_HEIGHT][GAME_WIDTH];
	int		re_buffer;
	double	ply_angle;
	int		floor_text;
	int		ceiling_text;
	t_img	*image;
};

t_cub		*this(void);
void		print_cub(t_cub *cub);
void		rm_cub(t_cub *cub);
void		print_error(char *s);
t_game		*game(void);
t_render	*render(void);
t_data		*data(void);
void		init_vars(t_game *game, t_render *render);
void		init_textures(t_cub *cub, t_game *game);

#endif