#include "gnl.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int		i;

	i = 1;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (read(fd, buf, 1) == 0)
		return (NULL);
	while (i < BUFFER_SIZE - 1 && buf[i] != '\n')
	{
		
		if (read(fd, buf + i, 1) == 0)
			return (buf);
		i++;
	}
	/* if (buf[i] == 0) */
	/* 	return (NULL); */
	buf[i] = 0;
	return(buf);
}
