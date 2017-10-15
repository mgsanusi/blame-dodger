#include "jsonparse.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
long int atol new_atol (const char *str);
int new_atoi (const char *str);
int new_strncmp (const char *str1, const char *str2, size_t num);
long int atol new_atol (const char *str);
int new_atoi (const char *str);
int
new_strncmp (const char *str1, const char *str2, size_t num)
{
  return strncmp (str1, str2, num);
}

long int atol new_atol (const char *str);
int
new_atoi (const char *str)
{
  return atoi (str);
}

long int atol
new_atol (const char *str)
{
  return atol (str);
}
