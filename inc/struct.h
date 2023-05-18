/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:42:36 by grebin            #+#    #+#             */
/*   Updated: 2023/05/18 16:59:00 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"

typedef struct s_cub	t_cub;

struct s_cub{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor;
	char	*ceiling;
	char	**map;	
};

struct s_game{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
};

t_cub	*this(void);
void	print_cub(t_cub *cub);
void	rm_cub(t_cub *cub);
void	print_error(char *s);
t_game	*game(void);
void	init_vars(t_game *game);

#endif