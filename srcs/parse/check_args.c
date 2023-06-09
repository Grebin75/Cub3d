/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:32:32 by grebin            #+#    #+#             */
/*   Updated: 2023/05/18 01:08:47 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

void	exist(char *file)
{
	int	fd;
	if (ft_strncmp(ft_strrchr(file, '.'), ".xpm", 5))
		print_error("Invalid file format");
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		print_error("It's a directory");
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		print_error("Invalid file");
	}
}

void	check_path(t_cub *cub)
{
	exist(cub->no_texture);
	exist(cub->so_texture);
	exist(cub->we_texture);
	exist(cub->ea_texture);
}


int	numlen(int n)
{
	int i;

	i = 0;
	while (n /10 && ++i)
		n = n / 10;
	return (i);
}

int	check_colour(char *colour)
{
	int	i;
	int	ncount;
	int n;
	int rgb[3];

	i = 0;
	ncount = -1;
	n = 0;
	while (ncount < 2)
	{
		if (colour[i] < '0' || colour[i] > '9')
			print_error("Invalid colour format, try x,x,x\n");
		n = atoi(colour + i);
		if (n > 255 || n < 0)
			print_error("Colour have a invalid number\n");
		rgb[++ncount] = n;
		i += numlen(n);
		if ((colour[++i] && (colour[i] != ',' || ncount == 2)) || (!colour[i] && ncount < 2))
			print_error("Invalid colour format, try x,x,y\n");
		i++;
	}
	return (255 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}