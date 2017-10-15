#include <config.h>
#include <stddef.h>
#include "save-cwd.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "chdir-long.h"
#include "unistd--.h"
#include "cloexec.h"
void *new_malloc (size_t size);
void *
new_malloc (size_t size)
{
  return malloc (size);
}
