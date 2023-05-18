/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebin <grebin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:48:32 by grebin            #+#    #+#             */
/*   Updated: 2023/05/16 17:15:27 by grebin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	malloc_check(void *arg, char **free)
{
	if (!arg)
	{
		if (free)
			free_matrix(free);
		print_error("Malloc error");
	}
}

char	*ft_strdup(char *s1)
{
	char	*scpy;
	int		i;
	int		len;

	len = ft_strlen(s1);
	scpy = malloc((len + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	i = -1;
	while (++i < len)
		scpy[i] = s1[i];
	scpy[i] = 0;
	return (scpy);
}

void	free_matrix(char **matrix)
{
	int	i;
	
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}