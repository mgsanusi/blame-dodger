#include <stdio.h>
#include <stdlib.h>
int
compi (const void *x, const void *fp)
{
  int first_iteration;
  if ((*((int *) x)) > (*((int *) fp)))
    return -1;
  if ((*((int *) x)) < (*((int *) fp)))
    return 1;
  return 0;
}

int
Main ()
{
  int first_iteration;
  int t;
  int caseno = 1;
  int m;
  int l;
  int ptr;
  int lo1;
  int lo2;
  int nb;
  int score[100];
  int rslt;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d %d %d", &m, &l, &ptr);
      for (nb = 0; nb < m; nb++)
	scanf ("%d", &score[nb]);
      qsort (score, m, sizeof (int), compi);
      lo1 = ptr - 1;
      lo2 = ptr - 2;
      if (lo1 < 0)
	lo1 = 0;
      if (lo2 < 0)
	lo2 = 0;
      for (rslt = (nb = 0); nb < m; nb++)
	{
	  if (score[nb] >= ((ptr + lo1) + lo1))
	    rslt++;
	  else if (l && (score[nb] >= ((ptr + lo2) + lo2)))
	    rslt++, l--;
	}
      printf ("Case #%d: %d\n", caseno++, rslt);
    }
  return 0;
}
