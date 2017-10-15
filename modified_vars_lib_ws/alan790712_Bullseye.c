#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int b;
int m;
int n;
int v[1234];
int rslt;
void
dfs (int now, int eNow, int sum)
{
  if (now >= n)
    {
      if (rslt < sum)
	{
	  rslt = sum;
	}
      return;
    }
  int fileIndexHtml;
  for (fileIndexHtml = 0; fileIndexHtml <= eNow; ++fileIndexHtml)
    {
      dfs (now + 1,
	   ((eNow - fileIndexHtml) + m) < b ? (eNow - fileIndexHtml) + m : b,
	   sum + (fileIndexHtml * v[now]));
    }
}

int
Main ()
{
  int d;
  int fp;
  int fileIndexHtml;
  scanf ("%d", &d);
  for (fp = 1; fp <= d; ++fp)
    {
      scanf ("%d %d %d", &b, &m, &n);
      printf ("Case #%d: ", fp);
      for (fileIndexHtml = (rslt = 0); fileIndexHtml < n; ++fileIndexHtml)
	{
	  scanf ("%d", &v[fileIndexHtml]);
	}
      dfs (0, b, 0);
      printf ("%d\n", rslt);
    }
  return 0;
}
