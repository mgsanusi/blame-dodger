#include <stdio.h>
void
xassert (const char *file, int lineno)
{
  int first_iteration;
  printf ("Assertion failed: file %s, line %d.\n", file, lineno);
}
