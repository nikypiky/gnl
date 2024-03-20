#include "get_next_line.h"

int	get_line_len(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != 0)
		i++;
	return (i);
}

size_t	line_cat(char *dest, char *src)
{
	size_t	lens;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	lens = gnl_strlen(src);
	while (dest[i] != 0)
		i++;
	while (src[j] != 0 && src[j] != '\n' && j < lens)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (src[j] == '\n')
	{
		dest[i] = '\n';
		dest[i + 1] = 0;
	}
	else
		dest[i] = 0;
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

char	*write_line(int fd, char *buf, char *line_get, char *line_return)
{
	static int	i;

	while (1)
	{
		if (gnl_strlen(buf) == 0)
		{
			i = read(fd, buf, BUFFER_SIZE);
			// printf("read buf = %d\n", i);
			if (i == 0)
				return (line_return);
			buf[BUFFER_SIZE] = 0;
		}
		if (i < get_line_len(buf))
		{
			return (NULL);
		}
		line_get = malloc((gnl_strlen(line_return) + get_line_len(buf) + 2));
		*line_get = 0;
		gnl_strlcpy(line_get, line_return, gnl_strlen(line_return));
		free (line_return);
		line_cat(line_get, buf);
		line_move(buf, get_line_len(buf) + 1, gnl_strlen(buf));
		line_return = malloc(sizeof(char) * (gnl_strlen(line_get) + 1));
		strcpy(line_return, line_get);
		free (line_get);
		if (line_return[gnl_strlen(line_return) - 1] == '\n')
			return (line_return);
	}
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line_get;
	char		*line_return;

	line_get = NULL;
	line_return = NULL;
	if (!buf)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
		{
			free (buf);
			return (NULL);
		}
		*buf = 0;
	}
	if (read(fd, buf, 0) < 0)
	{
		return (NULL);
	}
	return (write_line(fd, buf, line_get, line_return));
}
