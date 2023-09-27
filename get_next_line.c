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
	while (i < BUFFER_SIZE - 1 && buf[i - 1] != '\n')
	{
		
		if (read(fd, buf + i, 1) == 0)
			return (buf);
		i++;
	}
	buf[i] = 0;
	/* printf("%i", BUFFER_SIZE); */
	return(buf);
}
