#include <stdio.h>
void xassert(const char *file, int lineno)
{
  printf("Assertion failed: file %s, line %d.\n", file, lineno);
}


