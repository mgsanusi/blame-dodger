#include <stdlib.h>
#include "lib/error.h"
void new_exit (int status);
void
new_exit (int status)
{
  return exit (status);
}
