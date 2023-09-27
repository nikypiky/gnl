#include <stdio.h>
#include <fcntl.h>
#include "gnl.h"

int	main(void)
{
	int		file;
	int		i;
	char	*s;
	
	file = open("test.txt", O_RDWR);
	for (i = 0; i < 1; i++)
	{
		s = get_next_line(file);
		printf("%s", s);
		free (s);
	}
	close(file);
}
