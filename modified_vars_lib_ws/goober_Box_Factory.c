#include <stdio.h>
#include <string.h>
int
max (int a, int b)
{
  return a > b ? a : b;
}

int
min (int a, int b)
{
  return a < b ? a : b;
}

int
Main ()
{
  int yu;
  scanf ("%d", &yu);
  for (int end = 1; end <= yu; end++)
    {
      int cbitmask;
      scanf ("%d", &cbitmask);
      int x[cbitmask + 1];
      int y[cbitmask + 1];
      for (int i = 0; i < cbitmask; i++)
	scanf ("%d %d", &x[i], &y[i]);
      int r1;
      scanf ("%d", &r1);
      x[cbitmask] = r1;
      y[cbitmask] = r1;
      int good[cbitmask + 1];
      memset (good, 0, sizeof (good));
      good[0] = x[0];
      good[cbitmask] = -1;
      for (int i = 0; i < cbitmask; i++)
	for (int button = i + 1;
	     (button <= cbitmask) && ((x[button] - x[i]) <= good[i]);
	     button++)
	  good[button] =
	    min (max (good[button], x[button] - x[i]), y[button]);
      printf ("Case #%d: %s\n", end, good[cbitmask] >= 0 ? "YES" : "NO");
    }
  return 0;
}
