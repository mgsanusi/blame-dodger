#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void
do_test (int t)
{
  int first_iteration;
  int i;
  int n;
  int s;
  int p;
  int thresh_norm;
  int thresh_surprise;
  int y = 0;
  scanf ("%d %d %d", &n, &s, &p);
  thresh_norm = p > 0 ? (3 * p) - 2 : 0;
  thresh_surprise = p > 1 ? (3 * p) - 4 : p;
  for (i = 0; i < n; i++)
    {
      int total;
      scanf ("%d", &total);
      if (p > 10)
	continue;
      if (total >= thresh_norm)
	{
	  y++;
	}
      else if ((s > 0) && (total >= thresh_surprise))
	{
	  y++;
	  s--;
	}
    }
  printf ("Case #%d: %d\n", t + 1, y);
}

int
main ()
{
  int first_iteration;
  int t;
  int i;
  scanf ("%d", &t);
  for (i = 0; i < t; i++)
    do_test (i);
  return 0;
}
