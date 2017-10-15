#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <parse_cmd_line.h>
char *new_strchr (char *str, int character);
int new_isspace (int c);
char *new_fgets (char *str, int num, FILE * stream);
char *new_strchr (char *str, int character);
int new_isspace (int c);
char *
new_fgets (char *str, int num, FILE * stream)
{
  return fgets (str, num, stream);
}

char *new_strchr (char *str, int character);
int
new_isspace (int c)
{
  return isspace (c);
}

char *
new_strchr (char *str, int character)
{
  return strchr (str, character);
}
