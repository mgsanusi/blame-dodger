#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include "resource-ext.h"
void *new_malloc (int size);
int new_atoi (const char *str);
void *new_malloc (int size);
int
new_atoi (const char *str)
{
  return atoi (str);
}

void *
new_malloc (int size)
{
  return malloc (size);
}
