#include <config.h>
#include "binary-io.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
int new_fclose (FILE * stream);
void new_exit (int status);
int new_fclose (FILE * stream);
void
new_exit (int status)
{
  return exit (status);
}

int
new_fclose (FILE * stream)
{
  return fclose (stream);
}
