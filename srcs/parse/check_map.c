#include "parse.h"

char	**map_copy(char **map)
{
	char	**new;
	int		i;

	i = -1;
	i = 0;
	while (map[++i] && !map[i][0])
		;
	if (i < 2)
		print_error("Map needs more lines");
	new = malloc(sizeof(char *) * (i + 1));
	if (!new)
		print_error("Malloc error");
	i = -1;
	while (map[++i] && !map[i][0])
		new[i] = ft_strdup(map[i]);
	new[i] = 0;
	return (new);
}


void	check_map(char **map)
{
	char	**new;
	/* int		i;
	int		j;

	i = -1; */
	new = map_copy(map);
/* 	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || )

		}

	} */

	free_matrix(new);
}
