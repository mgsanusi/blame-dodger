#include <config.h>
#include "uninorm.h"
#include <stdlib.h>
#include "unistr.h"
#include "progname.h"
#include "test-u32-normalize-big.h"
#include <stdio.h>
void new_free (void *ptr);
void
new_free (void *ptr)
{
  return free (ptr);
}
