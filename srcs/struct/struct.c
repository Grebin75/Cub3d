/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:44:00 by grebin            #+#    #+#             */
/*   Updated: 2023/05/18 14:26:46 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"

void	print_error(char *s)
{
	write(2, s, ft_strlen(s));
	rm_cub(this());
}

void	rm_cub(t_cub *cub)
{
	if (cub->no_texture)
		free(cub->no_texture);
	if (cub->so_texture)
		free(cub->so_texture);
	if (cub->we_texture)
		free(cub->we_texture);
	if (cub->ea_texture)
		free(cub->ea_texture);
	if (cub->floor)
		free(cub->floor);
	if (cub->ceiling)
		free(cub->ceiling);

	if (cub->map)
		free_matrix(cub->map);
	exit(0);
}

void	print_cub(t_cub *cub)
{
	int	i;

	i = -1;

	if (cub->no_texture)
		printf("NORTH: %s\n", cub->no_texture);
	if (cub->so_texture)
		printf("SOUTH: %s\n", cub->so_texture);
	if (cub->we_texture)
		printf("WEST: %s\n", cub->we_texture);
	if (cub->ea_texture)
		printf("EAST: %s\n", cub->ea_texture);
	if (cub->floor)
		printf("FLOOR: %s\n", cub->floor);
	if (cub->ceiling)
		printf("CEILING: %s\n", cub->ceiling);

	printf("MAP:\n");
	while (cub->map && cub->map[++i])
		printf("%s\n", cub->map[i]);

}

t_cub *this()
{
	static t_cub	cub;

	return (&cub);
}
