#include <config.h>
#include <unistd.h>
#include <stddef.h>
#include "dcethread-private.h"
#include "dcethread-util.h"
#include "dcethread-debug.h"
#include "dcethread-exception.h"
int new_read(int fd, void *buf, int count);
int new_read(int fd, void *buf, int count)
{
	return read(fd, buf, count);
}
