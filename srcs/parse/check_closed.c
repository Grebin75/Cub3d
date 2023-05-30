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
	printf("ABERTO BAIXO\n");
	rm_cub(this());
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
	printf("ABERTO CIMA\n");
	rm_cub(this());
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
	printf("ABERTO DIREITA\n");
	rm_cub(this());
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
	printf("ABERTO ESQUERDA\n");
	rm_cub(this());
}

void	check_all(int i, int j)
{
	check_down(i, j);
	check_right(i, j);
	check_up(i, j);
	check_left(i, j);
}
