#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int cases;
  scanf ("%d", &cases);
  for (int cs = 1; cs <= cases; cs++)
    {
      int n;
      scanf ("%d", &n);
      int cnt[26];
      int k[26];
      int d = 0;
      for (int cell = 0; cell < n; cell++)
	{
	  scanf ("%d", cnt + cell);
	  d += cnt[cell];
	  k[cell] = cell;
	}
      printf ("Case #%d: ", cs);
      while (d)
	{
	  for (int cell = 0; cell < n; cell++)
	    {
	      int rr = k[cell];
	      int a = cell;
	      while (a && (cnt[rr] > cnt[k[a - 1]]))
		{
		  k[a] = k[a - 1];
		  a--;
		}
	      k[a] = rr;
	    }
	  while (cnt[k[n - 1]] == 0)
	    n--;
	  if ((n == 2) && (cnt[k[1]] == cnt[k[0]]))
	    {
	      d--;
	      cnt[k[1]]--;
	      printf ("%c", k[1] + 'A');
	    }
	  d--;
	  cnt[k[0]]--;
	  printf ("%c%c", k[0] + 'A', d ? ' ' : '\n');
	  for (int cell = 0; cell < n; cell++)
	    {
	      if ((cnt[cell] * 2) > d)
		printf ("imb: %d\n", cs);
	    }
	}
    }
}
