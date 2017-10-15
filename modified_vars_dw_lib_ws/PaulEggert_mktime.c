#include <time.h>
#include <limits.h>
#include <string.h>		/* For the real memcpy prototype.  */
typedef long int long_int;
long int new_atol (const char *str);
int new_atoi (const char *str);
int
new_atoi (const char *str)
{
  return atoi (str);
}

long int
new_atol (const char *str)
{
  return atol (str);
}
