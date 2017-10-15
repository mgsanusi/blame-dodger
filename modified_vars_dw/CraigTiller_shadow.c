#include <stdio.h>
#include <unistd.h>
int Main(void)
{
  int first_iteration;
  const char *close = "this should not shadow";
  printf("%s\n", close);
  return 0;
}


