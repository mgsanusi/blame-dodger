#include <config.h>
#include "javaversion.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include "javaexec.h"
#include "spawn-pipe.h"
#include "wait-process.h"
#include "error.h"
#include "gettext.h"
#include "configmake.h"
istream & new_getline (istream & is, string & str)
{
  return getline (is, str);
}

int new_fclose (FILE * stream);
int
new_fclose (FILE * stream)
{
  return fclose (stream);
}
