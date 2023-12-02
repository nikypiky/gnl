#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i <= size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
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

	lens = ft_strlen(src);
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

char	*buf_not_full(char *buf)
{
	size_t	line_len;
	char	*line;

	line_len = get_line_len(buf) + 1;
	if (buf[0] == '\n')
		line = (char *)malloc(sizeof(char) * 1);
	else
		line = (char *)malloc(sizeof(char) * line_len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buf, line_len);
	line_move(buf, line_len, ft_strlen(buf));
	return (line);
}

char	*write_line(int fd, char *buf, char *line_total, size_t line_len_total)
{
	char		*line;
	size_t		buf_len;
	size_t		line_len;

	buf_len = ft_strlen(buf);
	line = NULL;
	if (buf_len < BUFFER_SIZE && buf_len != 0)
	{
		line = buf_not_full(buf);
		line_len = get_line_len(line);
	}
	else
	{
		buf_len = read(fd, buf, BUFFER_SIZE);
		line_len = get_line_len(buf) + 1;
		line = (char *)malloc(sizeof(char) * (line_len_total + line_len + 1));
		if (!line)
			return (NULL);
		if (line_total)
		{
			ft_strlcpy(line, line_total, line_len_total);
			free (line_total);
			line_total = NULL;
		}
		line_cat(line, buf);
		if (buf_len > line_len)
			line_move(buf, line_len, buf_len);
		if (BUFFER_SIZE > buf_len)
		{
			buf = NULL;
			return (line);
		}
	}
	if (buf_len > line_len)
		return (line);
	return (write_line(fd, buf, line, (line_len_total + line_len)));
}

char	*alt_get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = NULL;
	if (!buf)
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || alt_descriptor_test(fd, buf) == -1)
		return (NULL);
	// line = write_line(fd, buf, line, 0);
	return(write_line(fd, buf, line, 0));
}
