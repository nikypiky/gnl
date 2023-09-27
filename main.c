#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "gnl.h"

int	main(void)
{
	int		file;
	int		i = 0;
	char	*s;
	
	file = open("test.txt", O_RDWR);
	while ((s = get_next_line(file)) != NULL)
	{
		printf("%s", s);
		free (s);
		i++;
	}
	printf("\ni=%i buffer=%i", i, BUFFER_SIZE);
	/* for (i = 0; i < 9; i++) */
	/* { */
	/* 	s = get_next_line(file); */
	/* 	printf("%s", s); */
	/* 	free (s); */
	/* } */
	close(file);
}
