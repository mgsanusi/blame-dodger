#include <config.h>
#include "stdio-safer.h"
#include <errno.h>
#include <unistd.h>
#include "unistd-safer.h"
#include "binary-io.h"
int new_fclose (FILE * stream);
int
new_fclose (FILE * stream)
{
  return fclose (stream);
}
