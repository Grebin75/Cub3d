/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:12:10 by gade-alm          #+#    #+#             */
/*   Updated: 2023/07/27 09:46:11 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

static void	check_down(int i, int j)
{
	while (i < game()->height && j < ft_strlen(this()->map[i]))
	{
		if (!this()->map[i][j] || this()->map[i][j] == ' ')
			break ;
		if (this()->map[i][j] == '1')
			return ;
		i++;
	}
	print_error("Error:\nMap is open\n");
}

static void	check_up(int i, int j)
{
	while (i >= 0)
	{
		if (!this()->map[i][j] || this()->map[i][j] == ' ')
			break ;
		if (this()->map[i][j] == '1')
			return ;
		else
			i--;
	}
	print_error("Error:\nMap is open\n");
}

static void	check_right(int i, int j)
{
	while (j <= ft_strlen(this()->map[i]))
	{
		if (this()->map[i][j] == ' ' || !this()->map[i][j])
			break ;
		if (this()->map[i][j] == '1')
			return ;
		j++;
	}
	print_error("Error:\nMap is open\n");
}

static void	check_left(int i, int j)
{
	while (j >= 0)
	{
		if (this()->map[i][j] == ' ' || !this()->map[i][j])
			break ;
		if (this()->map[i][j] == '1')
			return ;
		j--;
	}
	print_error("Error:\nMap is open\n");
}

void	check_all(int i, int j)
{
	check_down(i, j);
	check_right(i, j);
	check_up(i, j);
	check_left(i, j);
	check_surround(i, j);
}
