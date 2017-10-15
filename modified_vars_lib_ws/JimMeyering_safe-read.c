#include <config.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
ssize_t new_read(int fd, void *buf, size_t count)
{
	return read(fd, buf, count);
}
