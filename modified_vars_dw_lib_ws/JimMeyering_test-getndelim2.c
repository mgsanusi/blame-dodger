#include <config.h>
#include "getndelim2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include <stddef.h>
#include <stddef.h>
#include <stddef.h>
FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, int num);
int new_fclose (FILE * stream);
void *new_malloc (int size);
int new_strcmp (const char *str1, const char *str2);
void new_free (void *ptr);
int new_memcmp (const void *ptr1, const void *ptr2, int num);
FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, int num);
int new_fclose (FILE * stream);
void *new_malloc (int size);
int new_strcmp (const char *str1, const char *str2);
void new_free (void *ptr);
int
new_memcmp (const void *ptr1, const void *ptr2, int num)
{
  return memcmp (ptr1, ptr2, num);
}

FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, int num);
int new_fclose (FILE * stream);
void *new_malloc (int size);
int new_strcmp (const char *str1, const char *str2);
void
new_free (void *ptr)
{
  return free (ptr);
}

FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, int num);
int new_fclose (FILE * stream);
void *new_malloc (int size);
int
new_strcmp (const char *str1, const char *str2)
{
  return strcmp (str1, str2);
}

FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, int num);
int new_fclose (FILE * stream);
void *
new_malloc (int size)
{
  return malloc (size);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

void *new_memset (void *ptr, int value, int num);
int
new_fclose (FILE * stream)
{
  return fclose (stream);
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
