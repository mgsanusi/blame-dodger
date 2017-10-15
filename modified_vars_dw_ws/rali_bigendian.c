#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int int_var = 1;
  unsigned char *ch_arr = (unsigned char *) (&int_var);
  if (ch_arr[0] == 0)
    return 0;
  else
    return 1;
}
