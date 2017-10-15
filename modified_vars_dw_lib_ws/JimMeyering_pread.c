#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
int new_read(int fd, void *buf, int count);
int new_read(int fd, void *buf, int count)
{
    return read(fd, buf, count);
}
