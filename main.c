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
	/* i = read(file, s, 0); */
	while (i < 18)
	{
		s = alt_get_next_line(file);
		printf("%s", s);
		free (s);
		i++;
	}
	close(file);
}
