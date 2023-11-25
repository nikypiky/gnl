#include "get_next_line.h"

int	descriptor_test(int fd, char *buf)
{
	int	i;

	i = (read(fd, buf, 0));
	if (i <= 0)
		free (buf);
	return(i);
}

int line_len(char *buf)
{
	size_t	i;

	i = 0;
	while (c[i] != '/n')
		i++;
	return (i);
}

char	*alt_get_next_line(int fd)
{
	char	*buf;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (descriptor_test(fd, buf) <= 0)
		return (NULL);
	while (i < BUFFER_SIZE - 1 && buf[i - 1] != '\n')
	{
		if (read(fd, buf + i, 1) == 0)
			return (buf);
		i++;
	}
	buf[i] = 0;
	return(buf);
}
