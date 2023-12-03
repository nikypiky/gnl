#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	gnl_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (c)
	{
	while (c[i] != 0 || i < BUFFER_SIZE)
		i++;
	}
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (gnl_strlen(src));
	while (i <= size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (gnl_strlen(src));
}

int	alt_descriptor_test(int fd, char *buf)
{
	int	i;

	i = (read(fd, buf, 0));
	if (i < 0)
		free (buf);
	return(i);
}

int get_line_len(char *buf)
{
	size_t	i;

	i = 0;
	while ((buf[i] != '\n' && i < BUFFER_SIZE) && buf[i] != 0)
		i++;
	return (i);
}

size_t	line_cat(char *dest, const char *src)
{
	size_t	lens;

	lens = gnl_strlen(src);
	while (*dest)
		dest++;
	while (*src && src[-1] != '\n')
		*dest++ = *src++;
	*dest = '\0';
	return (lens);
}

void	line_move(char *buf, int line_len, int buf_len)
{
	int	i;

	i = 0;
	while (line_len < buf_len)
	{
		buf[i] = buf[line_len];
		i++;
		line_len++;
	}
	buf[i] = 0;
}

char	*write_line(int fd, char *buf)
{
	char	*line_collect;
	char	*line_return;

	while (1)
	{
		if (read(fd, buf, BUFFER_SIZE) <= 0)
			return (NULL);
		line_collect = malloc(sizeof(char) * (strlen(line_collect) + get_line_len(buf)));
		gnl_strlcpy(line_collect, line_return, gnl_strlen(line_return));
		free (line_return);
		line_move(buf, get_line_len(buf), gnl_strlen(buf));
		line_return = malloc(sizeof(char) * strlen(line_collect));
		strcpy(line_return, line_collect);
		free (line_collect);
		if (line_return[gnl_strlen(line_return)] == '\n')
			return (line_return);
	}
}

char	*alt_get_next_line(int fd)
{
	static char	*buf;

	if (!buf)
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || alt_descriptor_test(fd, buf) < 0)
		return (NULL);
	// line = write_line(fd, buf, line, 0);
	return(write_line(fd, buf));
}
