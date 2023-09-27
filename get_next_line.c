#include "gnl.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (i < BUFFER_SIZE - 1 && buf[i - 1] != '\n')
	{
		read (fd, buf + i, 1);
		i++;
	}
	buf[i] = 0;
	return(buf);
}
