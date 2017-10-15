#include <config.h>
#include <stdio.h>
#include <stdlib.h>
void new_exit (int status);
void
new_exit (int status)
{
  return exit (status);
}
