#include<stdio.h>
int u1[10001];
int u2[10001];
int u3[10001];
int sum[10001][10001];
int aa[5000];
int bb[5000];
int cc[5000];
int ind[10001];
int hai[100000];
int
main ()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int r;
  int jj;
  int a;
  int b;
  int c;
  int size;
  int count = 0;
  int res;
  int add;
  scanf ("%d", &size);
  while (size--)
    {
      fprintf (stderr, "rest input = %d\n", size);
      for (i = 0; i < 10001; i++)
	for (j = 0; j < 10001; j++)
	  sum[i][j] = 0;
      add = 0;
      scanf ("%d", &n);
      for (i = 0; i < n; i++)
	scanf ("%d%d%d", aa + i, bb + i, cc + i);
      for (i = 0; i < 10001; i++)
	u1[i] = (u2[i] = 0);
      for (i = 0; i < n; i++)
	u1[aa[i]] = (u2[bb[i]] = 1);
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
      for (r = 0; r < n; r++)
	{
	  a = aa[r], b = bb[r], c = cc[r];
	  if (((a == 0) && (b == 0)) && (c == 0))
	    {
	      add++;
	      continue;
	    }
	  for (i = a; i < 10001; i++)
	    if (u1[i])
	      for (jj = ind[b];; jj++)
		{
		  j = hai[jj];
		  if (((10000 - i) - j) < c)
		    break;
		  sum[i][j]++;
		}
	}
      res = 0;
      for (i = 0; i < 10001; i++)
	for (j = 0; j < 10001; j++)
	  if (res < sum[i][j])
	    res = sum[i][j];
      printf ("Case #%d: %d\n", ++count, res + add);
    }
  return 0;
}
