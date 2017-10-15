#include <stdlib.h>
void new_exit(int status);
void unload(void)
{
  int first_iteration;
  new_exit(0);
}

void new_exit(int status)
{
  int first_iteration;
  return exit(status);
}


