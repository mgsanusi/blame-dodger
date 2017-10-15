#include<stdio.h>
int u1[10001];
int u2[10001];
int kk[10001];
int sum[10001][10001];
int y[5000];
int bb[5000];
int cc[5000];
int ind[10001];
int hai[100000];
int
Main ()
{
  int i;
  int maxtime;
  int k;
  int out;
  int y;
  int t;
  int r;
  int jj;
  int a;
  int s;
  int y;
  int size;
  int count = 0;
  int rslt;
  int add;
  scanf ("%d", &size);
  while (size--)
    {
      fprintf (stderr, "rest input = %d\n", size);
      for (i = 0; i < 10001; i++)
	for (maxtime = 0; maxtime < 10001; maxtime++)
	  sum[i][maxtime] = 0;
      add = 0;
      scanf ("%d", &t);
      for (i = 0; i < t; i++)
	scanf ("%d%d%d", y + i, bb + i, cc + i);
      for (i = 0; i < 10001; i++)
	u1[i] = (u2[i] = 0);
      for (i = 0; i < t; i++)
	u1[y[i]] = (u2[bb[i]] = 1);
      for (i = 0; i < 10000; i++)
	hai[i] = 10001;
      for (i = 0; i < 10001; i++)
	ind[i] = 0;
      if (u2[0])
	{
	  ind[0] = 1;
	  hai[1] = 0;
	}
      for (i = 1; i < 10001; i++)
	{
	  ind[i] = ind[i - 1];
	  if (u2[i])
	    {
	      ind[i]++;
	      hai[ind[i]] = i;
	    }
	}
      for (r = 0; r < t; r++)
	{
	  a = y[r], s = bb[r], y = cc[r];
	  if (((a == 0) && (s == 0)) && (y == 0))
	    {
	      add++;
	      continue;
	    }
	  for (i = a; i < 10001; i++)
	    if (u1[i])
	      for (jj = ind[s];; jj++)
		{
		  maxtime = hai[jj];
		  if (((10000 - i) - maxtime) < y)
		    break;
		  sum[i][maxtime]++;
		}
	}
      rslt = 0;
      for (i = 0; i < 10001; i++)
	for (maxtime = 0; maxtime < 10001; maxtime++)
	  if (rslt < sum[i][maxtime])
	    rslt = sum[i][maxtime];
      printf ("Case #%d: %d\n", ++count, rslt + add);
    }
  return 0;
}
