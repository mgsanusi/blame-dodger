#include <stdio.h>
int
Main (void)
{
  int b;
  int cas;
  int n;
  int k;
  int dy;
  scanf ("%d", &b);
  for (cas = 1; cas <= b; cas++)
    {
      scanf ("%d %d", &n, &k);
      dy = (1 << n) - 1;
      printf ("Case #%d: %s\n", cas, (k & dy) == dy ? "ON" : "OFF");
    }
  return 0;
}
