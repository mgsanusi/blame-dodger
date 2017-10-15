#include <config.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include <stddef.h>
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count);
int new_atoi(const char *str);
int new_read(int fd, void *buf, int count)
{
    return read(fd, buf, count);
}

int new_atoi(const char *str)
{
    return atoi(str);
}
