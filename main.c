#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	file;
	
	file = open("test.txt", O_RDWR);
	write(file, "write test 1", 12);
	close(file);
	/* printf("d", file); */	
	/* get_next_line(4); */
}
