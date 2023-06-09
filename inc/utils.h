#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include "struct.h"

// ALLOCATION

void	free_matrix(char **matrix);
char	*ft_strdup(char *s1);
void	malloc_check(void *arg, char **free);

// STRING

char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *str);
long	ft_atoi(char *s);

#endif