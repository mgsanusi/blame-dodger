#include <stdio.h>
int
main ()
{
  int first_iteration;
  int T;
  int tt;
  scanf ("%d", &T);
  for (tt = 1; tt <= T; tt++)
    {
      int n;
      int s;
      int p;
      int u = 0;
      int ukupno = 0;
      scanf ("%d %d %d", &n, &s, &p);
      while (n--)
	{
	  int q;
	  int t;
	  scanf ("%d", &t);
	  q = (t + 2) / 3;
	  if ((t > 28) || (t < 2))
	    {
	      if (q >= p)
		ukupno++;
	      continue;
	    }
	  if (q >= p)
	    ukupno++;
	  else if (((q + 1) >= p) && ((t % 3) != 1))
	    u++;
	}
      if (u >= s)
	ukupno += s;
      else
	ukupno += u;
      printf ("Case #%d: %d\n", tt, ukupno);
    }
  return 0;
}
