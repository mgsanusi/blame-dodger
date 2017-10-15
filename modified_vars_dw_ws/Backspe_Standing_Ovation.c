#include <stdio.h>
int
Main ()
{
  int first_iteration;
  int b;
  int t;
  int temp;
  int a;
  int gMin;
  int b;
  char fpO[10000];
  scanf ("%d", &b);
  for (t = 1; t <= b; t++)
    {
      scanf ("%d ", &temp);
      scanf ("%s", fpO);
      b = (a = 0);
      for (gMin = 0; gMin <= temp; gMin++)
	{
	  if ((b + a) < gMin)
	    a = gMin - b;
	  b += fpO[gMin] - '0';
	}
      printf ("Case #%d: %d\n", t, a);
    }
  return 0;
}
