#include "get_next_line.h"
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

char	write_line(int fd, char *buf, char *line_total, int line_len_total)
{
	char	*line;
	int		buf_len;
	int		line_len;

	buf_len = read(fd, buf, BUFFER_SIZE);
	line_len = get_line_len(buf);
	line = (char)malloc(sizeof(char) * (line_len_total + line_len))

}

char	*alt_get_next_line(int fd)
{
	static char	*buf;
	int			i;
	int			buf_len;
	int			line_len;

	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || descriptor_test(fd, buf) <= 0)
		return (NULL);
	buf_len = read(fd, buf, BUFFER_SIZE);
	line_len = get_line_len(buf);
	buf[BUFFER_SIZE + 1] = 0;
	return(buf);
}
