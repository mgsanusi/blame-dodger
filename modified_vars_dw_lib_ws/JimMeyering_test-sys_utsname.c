#include <config.h>
#include <sys/utsname.h>
#include <string.h>
char *new_strcpy (char *destination, const char *source);
char *
new_strcpy (char *destination, const char *source)
{
  return strcpy (destination, source);
}
