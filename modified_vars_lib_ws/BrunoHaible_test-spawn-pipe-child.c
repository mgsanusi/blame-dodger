#include <config.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include <stddef.h>
ssize_t new_read(int fd, void *buf, size_t count)
{
	return read(fd, buf, count);
}

int new_atoi(const char *str);
int new_atoi(const char *str)
{
	return atoi(str);
}
