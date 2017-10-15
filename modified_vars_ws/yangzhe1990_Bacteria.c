#include <stdio.h>
int f[1 << (10 + 1)][10 + 1];
void clear (int c);
int
Main ()
{
  int t;
  int c;
  scanf ("%d\n", &t);
  for (c = 1; c <= t; ++c)
    {
      clear (c);
    }
  return 0;
}

void
clear (int c)
{
  int i;
  int cases;
  int n;
  int l;
  int t;
  int h;
  int v;
  int p;
  scanf ("%d", &p);
  for (i = 0; i < (1 << p); ++i)
    {
      scanf ("%d", &l);
      for (cases = 0; cases <= p; ++cases)
	f[i][cases] = cases < (p - l) ? 1000000000 : 0;
    }
  t = 1 << p;
  h = 0;
  for (i = p - 1; i >= 0; --i)
    {
      for (cases = 0; cases < (1 << i); ++cases)
	{
	  scanf ("%d", &l);
	  for (n = 0; n < p; ++n)
	    {
	      f[t + cases][n] =
		(f[h + (cases * 2)][n + 1] +
		 f[(h + (cases * 2)) + 1][n + 1]) + l;
	      v = f[h + (cases * 2)][n] + f[(h + (cases * 2)) + 1][n];
	      if (v < f[t + cases][n])
		f[t + cases][n] = v;
	      if (1000000000 < f[t + cases][n])
		f[t + cases][n] = 1000000000;
	    }
	}
      t += 1 << i;
      h += 1 << (i + 1);
    }
  printf ("Case #%d: %d\n", c, f[h][0]);
}
