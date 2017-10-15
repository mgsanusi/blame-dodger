#include <config.h>
#include "argmatch.h"
#include <stdlib.h>
#include "progname.h"
#include "macros.h"
void new_exit (int status);
void
new_exit (int status)
{
  return exit (status);
}
