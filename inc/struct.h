/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:42:36 by grebin            #+#    #+#             */
/*   Updated: 2023/05/18 14:27:39 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"

typedef struct s_cub t_cub;
/* typedef struct s_game t_game;
typedef struct s_img t_img; */

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

/* struct s_img{
	void	*img;
	char	*addr;
	t_img	*next;
};

struct s_game{
	void	*mlx;
	void	*win;
	int		f_rgb;
	int		c_rgb;
	char	**map;
}; */

t_cub 	*this(void);
void	print_cub(t_cub *cub);
void	rm_cub(t_cub *cub);
void	print_error(char *s);

#endif
