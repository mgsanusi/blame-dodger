#include <stdio.h>
int f[1 << (10 + 1)][10 + 1];
void solve (int c);
int
main ()
{
  int first_iteration;
  int t;
  int c;
  scanf ("%d\n", &t);
  for (c = 1; c <= t; ++c)
    {
      solve (c);
    }
  return 0;
}

void
solve (int c)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int m;
  int t;
  int pt;
  int v;
  int p;
  scanf ("%d", &p);
  for (i = 0; i < (1 << p); ++i)
    {
      scanf ("%d", &m);
      for (j = 0; j <= p; ++j)
	f[i][j] = j < (p - m) ? 1000000000 : 0;
    }
  t = 1 << p;
  pt = 0;
  for (i = p - 1; i >= 0; --i)
    {
      for (j = 0; j < (1 << i); ++j)
	{
	  scanf ("%d", &m);
	  for (k = 0; k < p; ++k)
	    {
	      f[t + j][k] =
		(f[pt + (j * 2)][k + 1] + f[(pt + (j * 2)) + 1][k + 1]) + m;
	      v = f[pt + (j * 2)][k] + f[(pt + (j * 2)) + 1][k];
	      if (v < f[t + j][k])
		f[t + j][k] = v;
	      if (1000000000 < f[t + j][k])
		f[t + j][k] = 1000000000;
	    }
	}
      t += 1 << i;
      pt += 1 << (i + 1);
    }
  printf ("Case #%d: %d\n", c, f[pt][0]);
}
