/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:41:06 by grebin            #+#    #+#             */
/*   Updated: 2023/07/27 09:46:53 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

void	is_empty(char *arg, char *newarg)
{
	if (arg)
	{
		print_error("Error:\nInvalid Format\n");
		free(newarg);
	}
}

int	format_checker(char *str)
{
	if (ft_strncmp(ft_strrchr(str, '.'), ".cub", 5))
		print_error("Error:\nInvalid file format\n");
	return (0);
}

char	**file_to_str(char **file, int fd, int i)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
		file = file_to_str(file, fd, i + 1);
	if (!file)
		file = malloc(sizeof(char *) * (i + 1));
	if (!file)
		printf("Error:\nFile Error\n");
	file[i] = str;
	return (file);
}

char	**open_file(char *map)
{
	int		fd;

	fd = open(map, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		printf("Error:\nIt's a directory type\n");
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
		printf("Error:\nCheck name of the file\n");
	return (file_to_str(NULL, fd, 0));
}
