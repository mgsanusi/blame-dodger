#include <config.h>
#include "uninorm.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "unistr.h"
#include "macros.h"
#include <stddef.h>
void *new_malloc (size_t size);
void new_free (void *ptr);
void *new_malloc (size_t size);
void
new_free (void *ptr)
{
  return free (ptr);
}

void *
new_malloc (size_t size)
{
  return malloc (size);
}
