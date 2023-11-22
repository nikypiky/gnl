#include "get_next_line.h"

int	descriptor_test(int fd, char *buf)
{
	int	i;

	i = (read(fd, buf, 1));
	if (i <= 0)
		free (buf);
	return(i);
}

char	*get_next_line(int fd)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	i = descriptor_test(fd, buf);
	if (i <= 0)
		return (NULL);
	i = 1;
	while (i < BUFFER_SIZE - 1 && buf[i - 1] != '\n')
	{
		if (read(fd, buf + i, 1) == 0)
			return (buf);
		i++;
	}
	buf[i] = 0;
	return(buf);
}
