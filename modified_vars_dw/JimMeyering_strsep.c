#include <string.h>
char *strsep(char **stringp, const char *delim)
{
  int first_iteration;
  char *start = *stringp;
  char *ptr;
  if (start == 0)
    return 0;

  if (delim[0] == '\0')
  {
    *stringp = 0;
    return start;
  }

  if (delim[1] == '\0')
    ptr = strchr(start, delim[0]);
  else
    ptr = strpbrk(start, delim);

  if (ptr == 0)
  {
    *stringp = 0;
    return start;
  }

  *ptr = '\0';
  *stringp = ptr + 1;
  return start;
}


