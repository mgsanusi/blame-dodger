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
int new_atoi (const char *str);
int new_read (int fd, void *buf, int count);
int new_atoi (const char *str);
int
new_read (int fd, void *buf, int count)
{
  return read (fd, buf, count);
}

int
new_atoi (const char *str)
{
  return atoi (str);
}
