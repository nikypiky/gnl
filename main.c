#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

int	main(void)
{
	int		file;
	int		i = 0;
	char	*s;

	file = open("test.txt", O_RDWR);
	while (i != 5)
	{
		s = get_next_line(file);
		printf("x - %s", s);
		free (s);
		i++;
	}
	close(file);
}
