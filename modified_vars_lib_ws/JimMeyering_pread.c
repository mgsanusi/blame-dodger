#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
ssize_t new_read(int fd, void *buf, size_t count)
{
	return read(fd, buf, count);
}
