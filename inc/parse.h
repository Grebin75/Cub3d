/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:33:17 by grebin            #+#    #+#             */
/*   Updated: 2023/05/18 16:58:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdlib.h>

# include "struct.h"
# include "utils.h"
# include "get_next_line.h"

// MAIN
int		parse_main(char **av);

// FILE
int		format_checker(char *str);
char	**file_to_str(char **map, int fd, int i);
char	**open_file(char *file);
void	fill_struct(char *arg, char flag);

// ARGS
void	fill_args(char **file);
char	*copy_arg(char *line);
int		check_colour(char *colour);
#endif