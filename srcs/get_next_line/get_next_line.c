/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:45:25 by gade-alm          #+#    #+#             */
/*   Updated: 2023/05/16 11:43:58 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				re;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (1)
	{		
		re = 1;
		if (!buffer[0])
			re = read(fd, buffer, BUFFER_SIZE);
		if (re > 0)
			line = ft_get_line(buffer, line);
		if (re < 1 || is_newline(buffer))
			break ;
	}
	return (line);
}
