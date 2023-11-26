#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

int	descriptor_test(int fd, char *buf)
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
	while (buf[i] != '/n' && i < BUFFER_SIZE)
		i++;
	return (i);
}

size_t	line_cat(char *dest, char *src, size_t line_total, size_t line_len_total)
{
	size_t	lens;
	size_t	i;

	i = 0;
	while (*dest != '/n')
	{
		dest++;
		lens++;
	}
	while (i < size)
	{
		*dest++ = *src++;
		lens++;
		i++;
	}
	return (lens);
}

char	write_line(int fd, char *buf, char *line_total, size_t line_len_total)
{
	char	*line;
	size_t		buf_len;
	size_t		line_len;

	buf_len = read(fd, buf, BUFFER_SIZE);
	line_len = get_line_len(buf);
	line = (char *)malloc(sizeof(char) * (line_len_total + line_len))


}

char	*alt_get_next_line(int fd)
{
	static char	*buf;
	size_t			i;
	size_t			buf_len;
	size_t			line_len;

	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || descriptor_test(fd, buf) <= 0)
		return (NULL);
	buf_len = read(fd, buf, BUFFER_SIZE);
	line_len = get_line_len(buf);
	buf[BUFFER_SIZE + 1] = 0;
	return(buf);
}

int	cat_line
