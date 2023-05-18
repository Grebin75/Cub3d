#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Wrong number of arguments");
		return (0);
	}
	parse_main(av);
}
