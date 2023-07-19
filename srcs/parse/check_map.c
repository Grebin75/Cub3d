#include "../inc/parse.h"

static int	top_bottom_check(t_cub *cub)
{
	int	j;

	j = -1;
	while (cub->map[0][++j])
	{
		if (cub->map[0][j] != '1' && cub->map[0][j] != ' ')
		{
			printf("ERROR TOP");
			rm_cub(cub, game());
		}
	}
	return (1);
}

int	not_wall(char c)
{
	return (c == '0' || c == 'W' || c == 'S' || c == 'N' \
	|| c == 'E');
}

int	check_map(t_cub *cub, t_render *render)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map[++i])
	{
		if (!top_bottom_check(cub))
			return (0);
		j = 0;
		while (cub->map[i][j])
		{
			if ((i > 0 && i <= game()->height) && not_wall(cub->map[i][j]))
				check_all(i, j);
			j++;
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' ||
			cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				render->ply_x = j;
				render->ply_y = i;
				render->angle = 0 + (90 * (cub->map[i][j] == 'W')) + (180 * \
				(cub->map[i][j] == 'S')) + (270 * (cub->map[i][j] == 'E'));
			}
		}
	}
	return (0);
}
