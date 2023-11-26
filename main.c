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
	line_cat(x, y, 6, 0);
	while ((s = get_next_line(file)) != NULL)
	{
		printf("%s", s);
		free (s);
		i++;
	}
	printf("\ni=%i s=%s", i, x);
	free (s);
	close(file);
}
