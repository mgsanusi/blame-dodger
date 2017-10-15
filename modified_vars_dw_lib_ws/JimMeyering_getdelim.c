#include <config.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
int new_getc (FILE * stream);
void *new_malloc (int size);
void *new_realloc (void *ptr, int size);
int new_read (int fd, void *buf, int count);
int new_getc (FILE * stream);
void *new_malloc (int size);
void *new_realloc (void *ptr, int size);
int
new_read (int fd, void *buf, int count)
{
  return read (fd, buf, count);
}

int new_getc (FILE * stream);
void *new_malloc (int size);
void *
new_realloc (void *ptr, int size)
{
  return realloc (ptr, size);
}

int new_getc (FILE * stream);
void *
new_malloc (int size)
{
  return malloc (size);
}

int
new_getc (FILE * stream)
{
  return getc (stream);
}
