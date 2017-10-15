#include <config.h>
#include "uniwbrk.h"
#include <string.h>
#include "unistr.h"
#include <stddef.h>
#include <stddef.h>
#include "uniwbrk/wbrktable.h"
#include "u-wordbreaks.h"
#include <stdio.h>
#include <stdlib.h>
void *new_malloc (size_t size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
void *new_realloc (void *ptr, size_t size);
void *new_malloc (size_t size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
void *
new_realloc (void *ptr, size_t size)
{
  return realloc (ptr, size);
}

void *new_malloc (size_t size);
int new_fprintf (FILE * stream, const char *format, ...);
void
new_exit (int status)
{
  return exit (status);
}

void *
new_malloc (size_t size)
{
  return malloc (size);
}
