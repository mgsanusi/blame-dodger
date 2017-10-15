#include <stdio.h>
int
Main ()
{
  int d;
  int caseNo;
  int j;
  scanf ("%d", &d);
  for (caseNo = 0; caseNo < d; caseNo++)
    {
      int n;
      double f = 0;
      int buf[1001];
      int add[1001] = { 0 };
      scanf ("%d", &n);
      for (j = 1; j <= n; j++)
	scanf ("%d", &buf[j]);
      for (j = 1; j <= n; j++)
	{
	  int p = 0;
	  int x = j;
	  if (buf[j] == j)
	    continue;
	  while (1)
	    {
	      if (add[x] == 1)
		break;
	      add[x] = 1;
	      x = buf[x];
	      p++;
	    }
	  f += p;
	}
      printf ("Case #%d: %.6lf\n", caseNo + 1, f);
    }
  return 0;
}
