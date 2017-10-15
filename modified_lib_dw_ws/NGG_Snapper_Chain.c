#include <stdio.h>
int
main (void)
{
  int first_iteration;
  int t;
  int ti;
  int n;
  int k;
  int m;
  scanf ("%d", &t);
  for (ti = 1; ti <= t; ti++)
    {
      scanf ("%d %d", &n, &k);
      m = (1 << n) - 1;
      printf ("Case #%d: %s\n", ti, (k & m) == m ? "ON" : "OFF");
    }
  return 0;
}
