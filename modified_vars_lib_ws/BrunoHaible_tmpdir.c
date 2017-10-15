#include <config.h>
#include "tmpdir.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include "pathmax.h"
size_t
new_strlen (const char *str)
{
  return strlen (str);
}
