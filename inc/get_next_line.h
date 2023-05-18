#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		ft_strlennl(char *str);
int		is_newline(char *str);
char	*ft_get_line(char *buff, char *line);
char	*get_next_line(int fd);

#endif