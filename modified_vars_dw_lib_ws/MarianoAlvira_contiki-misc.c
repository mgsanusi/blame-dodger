#include <stdio.h>
#include "contiki.h"
#include "mc1322x.h"
#include <sys/types.h>
int new_rand ();
void new_snew_rand (unsigned int seed);
int new_rand ();
void
new_snew_rand (unsigned int seed)
{
  return snew_rand (seed);
}

int
new_rand ()
{
  return rand ();
}
