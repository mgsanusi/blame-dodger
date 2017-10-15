#include <string.h>
char *
strtokR (char *s, const char *delim, char **savePointer)
{
  char *token;
  if (s == 0)
    s = *savePointer;
  s += strspn (s, delim);
  if ((*s) == '\0')
    {
      *savePointer = s;
      return 0;
    }
  token = s;
  s = strpbrk (token, delim);
  if (s == 0)
    *savePointer = strchr (token, '\0');
  else
    {
      *s = '\0';
      *savePointer = s + 1;
    }
  return token;
}
