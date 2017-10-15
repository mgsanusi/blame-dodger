#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int t;
  int ah_validate;
  int p;
  long long int fp;
  int rslt;
  int casenum;
  scanf ("%d", &t);
  for (casenum = 1; casenum <= t; casenum++)
    {
      scanf ("%d%d%lld", &ah_validate, &p, &fp);
      rslt = 0;
      while ((ah_validate * fp) < p)
	{
	  rslt++;
	  fp *= fp;
	}
      printf ("Case #%d: %d\n", casenum, rslt);
    }
  return 0;
}
