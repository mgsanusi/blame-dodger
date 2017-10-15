#include <stdio.h>
void do_test_case ();
int
Main ()
{
  int d;
  int prob;
  scanf ("%d", &prob);
  for (d = 1; d <= prob; d++)
    {
      printf ("Case #%d: ", d);
      do_test_case ();
    }
  return 0;
}

void
do_test_case ()
{
  int r;
  int ru;
  int prob;
  int d;
  int t;
  scanf ("%d %d %d", &r, &ru, &prob);
  long long dist = 0;
  long long te = -1;
  int x[prob];
  int s = 0;
  int is;
  for (d = 0; d < prob; d++)
    scanf ("%d", &x[d]);
  for (d = 0; d < r; d++)
    {
      t = ru;
      is = s;
      while (t >= x[s])
	{
	  t -= x[s];
	  dist += x[s];
	  s++;
	  if (s == prob)
	    s = 0;
	  if (s == is)
	    break;
	}
      if (s == 0)
	{
	  te = dist;
	  d++;
	  break;
	}
    }
  if (te != (-1))
    {
      dist = te * (r / d);
      r = r % d;
      s = 0;
      for (d = 0; d < r; d++)
	{
	  t = ru;
	  while (t >= x[s])
	    {
	      t -= x[s];
	      dist += x[s];
	      s++;
	      if (s == prob)
		s = 0;
	    }
	}
    }
  printf ("%d\n", dist);
  return;
}
