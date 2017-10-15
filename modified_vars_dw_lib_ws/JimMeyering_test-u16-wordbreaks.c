#include <config.h>
#include "uniwbrk.h"
#include <stdlib.h>
#include "macros.h"
#include <stddef.h>
void *new_malloc (int size);
void new_free (void *ptr);
void *new_malloc (int size);
void
new_free (void *ptr)
{
  return free (ptr);
}

void *
new_malloc (int size)
{
  return malloc (size);
}
