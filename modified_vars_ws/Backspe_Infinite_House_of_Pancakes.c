#include <stdio.h>
int
Main ()
{
  int tmp;
  int d;
  int cases;
  int dy;
  int caseNo;
  int s;
  int i;
  int u;
  int flag;
  int c[1001];
  scanf ("%d", &tmp);
  for (d = 1; d <= tmp; d++)
    {
      scanf ("%d", &cases);
      for (i = 1; i < 1000; i++)
	c[i] = 0;
      c[0] = 2147483647;
      caseNo = 0;
      for (i = 0; i < cases; i++)
	{
	  scanf ("%d", &s);
	  c[s]++;
	  if (s > caseNo)
	    caseNo = s;
	}
      dy = caseNo;
      for (i = 1; i <= caseNo; i++)
	{
	}
      for (i = 1; i <= caseNo; i++)
	{
	  s = 0;
	  for (u = i + 1; u <= caseNo; u++)
	    {
	      s += c[u] * ((u - 1) / i);
	    }
	  if (dy > (s + i))
	    dy = s + i;
	}
      printf ("Case #%d: %d\n", d, dy);
    }
  return 0;
}
