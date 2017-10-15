#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int
Main ()
{
  int n;
  int t1;
  scanf ("%d", &n);
  for (t1 = 0; t1 < n; t1++)
    {
      printf ("Case #%d: ", t1 + 1);
      int casenum;
      int __;
      scanf ("%d %d", &casenum, &__);
      __++;
      int mod = 1 << casenum;
      if ((__ % mod) == 0)
	printf ("ON\n");
      else
	printf ("OFF\n");
    }
  return 0;
}
