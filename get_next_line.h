#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

char	*get_next_line(int fd);
char	*alt_get_next_line(int fd);
size_t	gnl_strlen(const char *c);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);

#endif
