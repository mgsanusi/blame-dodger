#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int t;
  int c;
  scanf ("%d", &t);
  for (c = 1; c <= t; c++)
    {
      int l;
      int n;
      int k;
      scanf ("%d %d", &n, &k);
      l = (1 << n) - 1;
      printf ("Case #%d: %s\n", c, (k & l) == l ? "ON" : "OFF");
    }
  return 0;
}
