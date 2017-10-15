#include <config.h>
#include "yesno.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "closein.h"
#include "binary-io.h"
int new_puts (const char *str);
int new_atoi (const char *str);
int new_puts (const char *str);
int
new_atoi (const char *str)
{
  return atoi (str);
}

int
new_puts (const char *str)
{
  return puts (str);
}
