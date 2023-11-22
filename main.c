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
	while ((s = get_next_line(1000)) != NULL)
	{
		printf("%s", s);
		free (s);
		i++;
	}
	printf("\ni=%i buffer=%i", i, BUFFER_SIZE);
	free (s);
	close(file);
}
