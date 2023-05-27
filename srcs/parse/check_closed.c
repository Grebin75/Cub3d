#include "parse.h"

static int	check_down(int i, int j)
{
	while (i < game()->height)
	{
		if (this()->map[i][j] == ' ' || !this()->map[i][j])
			break ;
		if (this()->map[i][j] == '1')
			return (1);
		i++;
	}
	printf("ABERTO BAIXO\n");
	return (0);
}

static int	check_up(int i, int j)
{
	while (i >= 0)
	{
		if (this()->map[i][j] == ' ' || !this()->map[i][j])
			break ;
		if (this()->map[i][j] == '1')
			return (1);
		else
			i--;
	}
	printf("ABERTO CIMA\n");
	return (0);
}

static int	check_right(int i, int j)
{
	while (j <= ft_strlen(this()->map[i]))
	{
		if (this()->map[i][j] == ' ' || !this()->map[i][j])
			break ;
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
		if (this()->map[i][j] == ' ' || !this()->map[i][j])
			break ;
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
