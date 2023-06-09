#include "cub3d.h"

int	ft_strlennl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	is_newline(char *str)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	j = 0;
	while (str[i])
	{
		if (ret)
			str[j++] = str[i];
		if (str[i] == '\n')
			ret = 1;
		str[i] = 0;
		i++;
	}
	return (ret);
}

char	*ft_get_line(char *buff, char *line)
{
	int		i;
	int		j;
	int		buff_size;
	char	*temp;

	buff_size = ft_strlennl(buff);
	temp = malloc(sizeof(char) * (buff_size + ft_strlennl(line) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		temp[i] = line[i];
		i++;
	}
	j = 0;
	while (j < buff_size)
		temp[i++] = buff[j++];
	temp[i] = '\0';
	if (line)
		free (line);
	return (temp);
}
