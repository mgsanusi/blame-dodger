#include <stdio.h>
#include <string.h>
#include "ihx2bin.h"
#include <stddef.h>
#include <stddef.h>
FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, size_t num);
int new_fclose (FILE * stream);
char *new_strchr (char *str, int character);
int new_fgetc (FILE * stream);
char *new_strncpy (char *destination, const char *source, size_t num);
FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, size_t num);
int new_fclose (FILE * stream);
char *new_strchr (char *str, int character);
int new_fgetc (FILE * stream);
char *
new_strncpy (char *destination, const char *source, size_t num)
{
  return strncpy (destination, source, num);
}

FILE *new_fopen (const char *filename, const char *mode);
void *new_memset (void *ptr, int value, size_t num);
int new_fclose (FILE * stream);
char *new_strchr (char *str, int character);
int
new_fgetc (FILE * stream)
{
  return fgetc (stream);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

void *new_memset (void *ptr, int value, size_t num);
int new_fclose (FILE * stream);
char *
new_strchr (char *str, int character)
{
  return strchr (str, character);
}

void *new_memset (void *ptr, int value, size_t num);
int
new_fclose (FILE * stream)
{
  return fclose (stream);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
