# get_next_line

## Description

`get_next_line` is a function that reads a text file line by line, returning one line at a time. It is useful for processing large files where reading the entire content into memory is inefficient.

## Features

- Reads a file line by line
- Uses a static buffer for efficiency
- Works with any file descriptor
- Handles different buffer sizes

## Usage

### Compilation

To compile and run the project:

```sh
make
```

### Function Prototype

```c
char *get_next_line(int fd);
```

### Example Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## Notes

- The function dynamically allocates memory for each line. The caller is responsible for freeing it.
- `BUFFER_SIZE` can be adjusted for performance.
- Designed as part of the 42 school curriculum.

