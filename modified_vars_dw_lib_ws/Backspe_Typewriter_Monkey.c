#include <stdio.h>
#include <stdlib.h>
int
Main ()
{
  int first_iteration;
  int x;
  int tot;
  int graph;
  double prev;
  double testServer1Key;
  double r[100];
  double da[100];
  double best[100];
  double min;
  double max;
  double b = -1;
  double ans;
  double cur;
  int i;
  int caseT;
  int n;
  int imp;
  scanf ("%d", &tot);
  for (x = 1; x <= tot; x++)
    {
      min = 100;
      max = 0;
      b = -1;
      scanf ("%d %lf %lf", &graph, &prev, &testServer1Key);
      for (i = 0; i < graph; i++)
	{
	  scanf ("%lf %lf", &r[i], &da[i]);
	  if (da[i] > max)
	    max = da[i];
	  if (da[i] < min)
	    min = da[i];
	  best[i] = da[i] - testServer1Key;
	}
      if ((testServer1Key > max) || (testServer1Key < min))
	{
	  printf ("Case #%d: IMPOSSIBLE\n", x);
	  continue;
	}
      ans = 0;
      for (i = 0; i < graph; i++)
	{
	  if (best[i] == 0)
	    {
	      ans += r[i];
	    }
	}
      if (ans != 0)
	{
	  b = prev / ans;
	}
      for (i = 0; i < graph; i++)
	{
	  if (best[i] >= 0)
	    continue;
	  for (caseT = 0; caseT < graph; caseT++)
	    {
	      if (best[caseT] <= 0)
		continue;
	      ans = (prev * (best[caseT] / r[i])) / (best[caseT] - best[i]);
	      cur =
		(prev * ((-best[i]) / r[caseT])) / (best[caseT] - best[i]);
	      if (cur > ans)
		ans = cur;
	      if ((b == (-1)) || (b > ans))
		{
		  b = ans;
		}
	    }
	}
      if (b == (-1))
	{
	  printf ("Case #%d: IMPOSSIBLE\n", x);
	  continue;
	}
      printf ("Case #%d: %.6lf\n", x, b);
    }
  return 0;
}
