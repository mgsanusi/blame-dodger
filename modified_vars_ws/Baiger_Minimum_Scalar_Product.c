#include <stdio.h>
int n;
int casenum;
int t[100];
int x[100][11];
int y[100][11];
int batch[11];
int minb[11];
int cnt1 = 0;
int min;
void
judge (int depth)
{
  if (depth > n)
    {
      int xia;
      int j;
      int r = 0;
      for (xia = 0; xia < casenum; xia++)
	for (j = 0; j < t[xia]; j++)
	  if (batch[x[xia][j]] == y[xia][j])
	    {
	      r++;
	      break;
	    }
      if ((r == casenum) && (cnt1 < min))
	{
	  min = cnt1;
	  for (xia = 1; xia <= n; xia++)
	    minb[xia] = batch[xia];
	}
    }
  else
    {
      batch[depth] = 0;
      judge (depth + 1);
      batch[depth] = 1;
      cnt1++;
      judge (depth + 1);
      cnt1--;
    }
}

int
Main ()
{
  int e;
  int xia;
  scanf ("%d", &e);
  for (xia = 1; xia <= e; xia++)
    {
      scanf ("%d%d", &n, &casenum);
      int j;
      int start;
      for (j = 0; j < casenum; j++)
	{
	  scanf ("%d", &t[j]);
	  for (start = 0; start < t[j]; start++)
	    scanf ("%d %d", &x[j][start], &y[j][start]);
	}
      min = 101;
      judge (1);
      if (min == 101)
	printf ("Case #%d: IMPOSSIBLE\n", xia);
      else
	{
	  printf ("Case #%d:", xia);
	  for (start = 1; start <= n; start++)
	    printf (" %d", minb[start]);
	  printf ("\n");
	}
    }
  return 0;
}
