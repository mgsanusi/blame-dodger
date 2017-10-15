#include <config.h>
#include "closein.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "binary-io.h"
#include "ignore-value.h"
void new_exit (int status);
void
new_exit (int status)
{
  return exit (status);
}
