#include "get_next_line.h"

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
	while (dest[i] != 0 )
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

char	*write_line(int fd, char *buf, char *line_collect, char *line_return)
{
	int	i;

	while (1)
	{
		if (gnl_strlen(buf) == 0)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (i < 0)
				return (NULL);
			if (i == 0)
				return (line_return);
			buf[BUFFER_SIZE] = 0;
		}
		line_collect = malloc(sizeof(char) * (gnl_strlen(line_return) + get_line_len(buf) + 2));
		*line_collect = 0;
		gnl_strlcpy(line_collect, line_return, gnl_strlen(line_return));
		free (line_return);
		line_cat(line_collect, buf);
		line_move(buf, get_line_len(buf) + 1, gnl_strlen(buf));
		line_return = malloc(sizeof(char) * (gnl_strlen(line_collect)+1));
		strcpy(line_return, line_collect);
		free (line_collect);
		if (line_return[gnl_strlen(line_return) - 1] == '\n')
			return (line_return);
	}
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line_collect;
	char		*line_return;

	line_collect = NULL;
	line_return = NULL;

	if (!buf)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		*buf = 0;
	}
	if (!buf || alt_descriptor_test(fd, buf) < 0)
		return (NULL);
	return(write_line(fd, buf, line_collect, line_return));
}
