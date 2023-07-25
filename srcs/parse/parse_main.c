/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:33:48 by grebin            #+#    #+#             */
/*   Updated: 2023/07/25 11:22:28 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

char	*copy_arg(char *line)
{
	char	*new;
	int		i;
	int		j;

	j = -1;
	i = ft_strlen(line);
	while (line[--i] && ((line[i] >= 8 && line[i] <= 13) || line[i] == 32))
		;
	new = malloc(sizeof(char) * (i + 2));
	while (line[++j] && j <= i)
		new[j] = line[j];
	new[j] = 0;
	return (new);
}

void	fill_struct2(char *arg, char flag)
{
	if (flag == 'E')
	{
		is_empty(this()->ea_texture, arg);
		this()->ea_texture = arg;
	}
	if (flag == 'F')
	{
		is_empty(this()->floor, arg);
		this()->floor = arg;
	}
	if (flag == 'C')
	{
		is_empty(this()->ceiling, arg);
		this()->ceiling = arg;
	}
}

void	fill_struct(char *arg, char flag)
{
	if (flag == 'N')
	{
		is_empty(this()->no_texture, arg);
		this()->no_texture = arg;
	}
	if (flag == 'S')
	{
		is_empty(this()->so_texture, arg);
		this()->so_texture = arg;
	}
	if (flag == 'W')
	{
		is_empty(this()->we_texture, arg);
		this()->we_texture = arg;
	}
	fill_struct2(arg, flag);
}

void	check_struct(t_cub *cub)
{
	if (!cub->ceiling)
		print_error("Missing args");
	if (!cub->floor)
		print_error("Missing args");
	if (!cub->no_texture)
		print_error("Missing args");
	if (!cub->so_texture)
		print_error("Missing args");
	if (!cub->ea_texture)
		print_error("Missing args");
	if (!cub->we_texture)
		print_error("Missing args");
	if (!cub->map)
		print_error("Missing args");
	verify_map(cub->map);
}

int	parse_main(char **av)
{
	char	**file;

	format_checker(av[1]);
	file = open_file(av[1]);
	fill_args(file);
	check_struct(this());
	check_path(this());
	check_map(this(), render());
	this()->f_rgb = check_colour(this()->floor);
	this()->c_rgb = check_colour(this()->ceiling);
	return (0);
}
