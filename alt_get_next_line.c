#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

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
	while (buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	return (i + 1);
}

size_t	line_cat(char *dest, char *src, size_t line_len_total, size_t line_len)
{
	size_t	lens;
	size_t	i;

	lens = 0;
	i = 0;
	while (lens < line_len_total)
	{
		dest++;
		lens++;
	}
	while (i < line_len && *dest != '\n')
	{
		*dest++ = *src++;
		lens++;
		i++;
	}
	return (lens);
}

void	line_move(char *buf, int line_len, int buf_len)
{
	int	i;

	i = 0;
	while (line_len < buf_len && buf[i] != '\n')
	{
		buf[i] = buf[line_len];
		i++;
		line_len++;
	}
	buf[i + 1] = 0;
}

char	*write_line(int fd, char *buf, char *line_total, size_t line_len_total)
{
	char		*line;
	size_t		buf_len;
	size_t		line_len;

	buf_len = read(fd, buf, BUFFER_SIZE);
	line_len = get_line_len(buf);
	line = (char *)malloc(sizeof(char) * (line_len_total + line_len));
	line_cat(line, line_total, line_len_total, 0);
	line_cat(line, buf, line_len_total, line_len);
	if (buf_len > line_len)
		line_move(buf, line_len, buf_len);
	return (line);
}

char	*alt_get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	/* size_t	i; */
	size_t		line_len;

	if (!buf)
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || alt_descriptor_test(fd, buf) == -1)
		return (NULL);
	line = write_line(fd, buf, line, 0);
	return(line);
}
