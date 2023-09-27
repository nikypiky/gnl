#include "gnl.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int		i = 26;

	buf = (char *)malloc(sizeof(char) * i);
	if (!buf)
		return (NULL);
	read(fd, buf, i);
	buf[i] = 0;
	return(buf);
}
