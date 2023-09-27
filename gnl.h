#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
# endif

char	*get_next_line(int fd);

#endif
