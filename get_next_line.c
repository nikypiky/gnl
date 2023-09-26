#include <unistd.h>

char	*get_next_line(int fd)
{
	write(1, "hello", fd);
	return("lol");
}
