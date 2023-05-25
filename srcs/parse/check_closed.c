#include "parse.h"

static int	check_down(int i, int j)
{
	while (this()->map[i][j])
	{
		if (this()->map[i][j] == '1')
			return (1);
		i++;
	}
	printf("ABERTO baixo\n");
	return (0);
}

static int	check_up(int i, int j)
{
	while (this()->map[i][j])
	{
		if (this()->map[i][j] == '1')
			return (1);
		i--;
	}
	printf("ABERTO cima\n");
	return (0);
}

static int	check_right(int i, int j)
{
	while (this()->map[i][j])
	{
		if (this()->map[i][j] == '1')
			return (1);
		j++;
	}
	printf("ABERTO DIREITA\n");
	return (0);
}

static int	check_left(int i, int j)
{
	while (j >= 0)
	{
		if (this()->map[i][j] == '1')
			return (1);
		j--;
	}
	printf("ABERTO ESQUERDA\n");
	return (0);
}

int	check_all(int i, int j)
{
	if (!check_up(i, j) || !check_down(i, j) \
	|| !check_left(i, j) || !check_right(i, j))
	{
		return (0);
	}
	return (1);
}
