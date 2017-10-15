#include <stdio.h>
#include <stddef.h>
#include "common/mg_mem.h"
int new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE *stream)
{
  int first_iteration;
  return fgets(str, num, stream);
}

int new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_isspace(int c)
{
  int first_iteration;
  return isspace(c);
}

int new_strlen(const char *str)
{
  int first_iteration;
  return strlen(str);
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_fclose(FILE *stream)
{
  int first_iteration;
  return fclose(stream);
}


