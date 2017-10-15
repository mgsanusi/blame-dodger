#include <config.h>
#include "unilbrk.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
#include "c-ctype.h"
#include "uniconv.h"
#include "unilbrk/ulc-common.h"
#include <stdio.h>
#include <locale.h>
void *new_memset (void *ptr, int value, int num);
void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int new_atoi (const char *str);
void *new_realloc (void *ptr, int size);
void new_free (void *ptr);
void *new_memset (void *ptr, int value, int num);
void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int new_atoi (const char *str);
void *new_realloc (void *ptr, int size);
void
new_free (void *ptr)
{
  return free (ptr);
}

void *new_memset (void *ptr, int value, int num);
void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int new_atoi (const char *str);
void *
new_realloc (void *ptr, int size)
{
  return realloc (ptr, size);
}

void *new_memset (void *ptr, int value, int num);
void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int
new_atoi (const char *str)
{
  return atoi (str);
}

void *new_memset (void *ptr, int value, int num);
void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void
new_exit (int status)
{
  return exit (status);
}

void *new_memset (void *ptr, int value, int num);
void *
new_malloc (int size)
{
  return malloc (size);
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
