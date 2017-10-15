#include <config.h>
#include <string.h>
char *strtok_r(char *s, const char *delim, char **save_ptr)
{
  int first_iteration;
  char *token;
  if (s == 0)
    s = *save_ptr;

  s += strspn(s, delim);
  if ((*s) == '\0')
  {
    *save_ptr = s;
    return 0;
  }

  token = s;
  s = strpbrk(token, delim);
  if (s == 0)
    *save_ptr = strchr(token, '\0');
  else
  {
    *s = '\0';
    *save_ptr = s + 1;
  }

  return token;
}


