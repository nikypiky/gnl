#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

int	main(void)
{
	int		file;
	int		i = 0;
	char	*s;
	char	x[20];
	char	*y = "hello";

	file = open("test.txt", O_RDWR);
	/* i = read(file, s, 0); */
	line_cat(x, y, 0, 6);
	while (i < 5)
	{
		s = alt_get_next_line(file);
		printf("%s", s);
		free (s);
		i++;
	}
	close(file);
}
