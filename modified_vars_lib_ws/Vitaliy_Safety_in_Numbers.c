#include <stdio.h>
int f[100][100];
int p[100][100];
int ac[100][100];
double good[100][100];
double
count (int h, double k, int num, int c1, int f2, int ti)
{
  double combine_table = k < 0 ? h : h - (10 * k);
  if ((ti < (f2 + 50)) || (ti < (num + 50)))
    {
      return 1000000000;
    }
  if (c1 < (f2 + 50))
    {
      return 1000000000;
    }
  if ((combine_table + 50) > ti)
    {
      k = ((h + 50) - ti) * 0.1;
    }
  combine_table = k < 0 ? h : h - (10 * k);
  if (((combine_table - 20) + 1e-10) > num)
    {
      return k + 1;
    }
  else
    {
      return k + 10;
    }
}

int
Main ()
{
  int nz;
  scanf ("%d", &nz);
  int _;
  for (_ = 0; _ < nz; _++)
    {
      printf ("Case #%d:", _ + 1);
      int n;
      int a;
      int h;
      scanf ("%d%d%d", &h, &n, &a);
      int i;
      int j;
      for (i = 0; i < n; i++)
	for (j = 0; j < a; j++)
	  {
	    scanf ("%d", &p[i][j]);
	  }
      for (i = 0; i < n; i++)
	for (j = 0; j < a; j++)
	  {
	    scanf ("%d", &f[i][j]);
	  }
      for (i = 0; i < n; i++)
	for (j = 0; j < a; j++)
	  {
	    good[i][j] = 1000000000;
	    ac[i][j] = 0;
	  }
      good[0][0] = -1000000000;
      while (1)
	{
	  int b = 1000000000;
	  int e = -1;
	  int y = -1;
	  for (i = 0; i < n; i++)
	    for (j = 0; j < a; j++)
	      if ((!ac[i][j]) && (b > good[i][j]))
		{
		  b = good[i][j];
		  e = i;
		  y = j;
		}
	  if (e == (-1))
	    {
	      break;
	    }
	  if ((e == (n - 1)) && (y == (a - 1)))
	    {
	      break;
	    }
	  ac[e][y] = 1;
	  double k = good[e][y];
	  if (e != 0)
	    {
	      double diff_cnt =
		count (h, k, f[e][y], p[e][y], f[e - 1][y], p[e - 1][y]);
	      if (diff_cnt < good[e - 1][y])
		{
		  good[e - 1][y] = diff_cnt;
		}
	    }
	  if (e != (n - 1))
	    {
	      double diff_cnt =
		count (h, k, f[e][y], p[e][y], f[e + 1][y], p[e + 1][y]);
	      if (diff_cnt < good[e + 1][y])
		{
		  good[e + 1][y] = diff_cnt;
		}
	    }
	  if (y != 0)
	    {
	      double diff_cnt =
		count (h, k, f[e][y], p[e][y], f[e][y - 1], p[e][y - 1]);
	      if (diff_cnt < good[e][y - 1])
		{
		  good[e][y - 1] = diff_cnt;
		}
	    }
	  if (y != (a - 1))
	    {
	      double diff_cnt =
		count (h, k, f[e][y], p[e][y], f[e][y + 1], p[e][y + 1]);
	      if (diff_cnt < good[e][y + 1])
		{
		  good[e][y + 1] = diff_cnt;
		}
	    }
	}
      double diff_cnt = good[n - 1][a - 1];
      if (diff_cnt < 0)
	{
	  diff_cnt = 0;
	}
      printf (" %lf\n", diff_cnt);
    }
  return 0;
}
