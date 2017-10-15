#include <config.h>
#include "long-options.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "version-etc.h"
void new_exit (int status);
void
new_exit (int status)
{
  return exit (status);
}
