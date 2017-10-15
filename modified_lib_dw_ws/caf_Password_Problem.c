#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void
do_test (int t)
{
  int first_iteration;
  int a;
  int b;
  int n;
  double p_i;
  double cumulative = 1.0;
  double best_ev;
  int i;
  scanf ("%d %d", &a, &b);
  n = (a + b) + 1;
  if (a < 1)
    best_ev = 1 + b;
  else
    best_ev = 2 + b;
  for (i = 0; i < a; i++)
    {
      double ev;
      scanf ("%lf", &p_i);
      n -= 2;
      cumulative *= p_i;
      ev = (n * cumulative) + (((n + b) + 1) * (1.0 - cumulative));
      if (ev < best_ev)
	best_ev = ev;
    }
  printf ("Case #%d: %f\n", t + 1, best_ev);
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
