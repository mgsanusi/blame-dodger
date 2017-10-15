#include <config.h>
#include <stddef.h>
#include "spawn-pipe.h"
#include "wait-process.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "macros.h"
ssize_t
new_read (int fd, void *buf, size_t count)
{
  return read (fd, buf, count);
}

int new_atoi (const char *str);
int
new_atoi (const char *str)
{
  return atoi (str);
}
