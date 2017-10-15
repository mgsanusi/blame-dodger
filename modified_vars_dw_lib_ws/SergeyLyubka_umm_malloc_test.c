#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "umm_malloc.h"
#include "umm_malloc_internal.h"
#include <stddef.h>
void *new_memset (void *ptr, int value, int num);
int new_rand ();
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
void *new_memset (void *ptr, int value, int num);
int new_rand ();
int new_fprintf (FILE * stream, const char *format, ...);
void
new_exit (int status)
{
  return exit (status);
}

void *new_memset (void *ptr, int value, int num);
int
new_rand ()
{
  return rand ();
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
