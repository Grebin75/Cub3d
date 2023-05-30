/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:52:36 by grebin            #+#    #+#             */
/*   Updated: 2023/05/30 11:34:36 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

void	verify_map(char **map)
{
	int	i;
	int	j;
	int	spawncounter;

	spawncounter = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E'\
			&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'W' \
			&& map[i][j] != 32)
				print_error("Invalid char");
			if (map[i][j] == 'S' && map[i][j] == 'W' && map[i][j] == 'E'\
			&& map[i][j] == 'N')
				spawncounter++;
		}
		if (spawncounter > 1)
			print_error("Multiple spawn locations");
	}
}

void fill_map(char **file, int i)
{
	int	j;
	int	k;
	char *line;

	line = NULL;
	j = 0;
	k = i;
	while (file[++i])
		++j;
	this()->map = malloc(sizeof(char *) * (j + 1));
	malloc_check(&line, file);
	j = -1;
	while (file[++k])
	{
		line = ft_strdup(file[k]);
		malloc_check(&line, file);
		this()->map[++j] = line;
	}
	this()->map[++j] = NULL;
}


int	is_valid(char *line)
{
	if (ft_strncmp("NO ", line, 3) == 0 || ft_strncmp("SO ", line, 3) == 0 || \
	ft_strncmp("WE ", line, 3) == 0 || ft_strncmp("EA ", line, 3) == 0 || \
	line[0] == 0)
		return (2);
	if (ft_strncmp("F ", line, 2) == 0 || ft_strncmp("C ", line, 2) == 0)
		return (1);
	return (0);
}


int	split_args(char *line, char **file)
{
	int		i;
	char	*arg;

	i = is_valid(line);
	if (!*line)
		return (0);
	while (line[++i] && ((line[i] >= 8 && line[i] <= 13) || line[i] == 32))
		;
	if (!line[i])
		return (0);
	arg = copy_arg(line + i);
	malloc_check(&line, file);
	fill_struct(arg, line[0]);
	return (1);
}

void	fill_args(char **file)
{
	int	i;
	int	ac;

	ac = 0;
	i = -1;
	while (file[++i])
	{
		if (!is_valid(file[i]) && ac != 6)
		{
			free_matrix(file);
			print_error("Invalid arguments format\n");
		}
		if (!is_valid(file[i]) && ac == 6)
		{
			fill_map(file, i - 1);
			break;
		}
		if (split_args(file[i], file))
			ac++;
	}
	free_matrix(file);
}
