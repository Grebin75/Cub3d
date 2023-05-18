#include "../inc/utils.h"

int		ft_strlen(char *str)
{
	int	len;

	len = -1;
	if (!str)
		return (0);
	while (str[++len])
		;
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	len = 0;
	str = (char *)s;
	if (!s)
		return (0);
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] == (unsigned char) c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0 || !s1 || !s2)
		return (0);
	while ((s1[a] != 0) && (s2 != 0) && (s1[a] == s2[a]) && (a < n - 1))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

long	ft_atoi(char *s)
{
	long	n;
	long	sig;

	n = 0;
	sig = 1;
	while (*s == 32 || (*s > 8 && *s < 14))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sig *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + sig * (*s - '0');
		s++;
	}
	return (n);
}
