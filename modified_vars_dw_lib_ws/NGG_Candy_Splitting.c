#include <stdio.h>
int
Main (void)
{
  int first_iteration;
  int j;
  int t2;
  scanf ("%d", &t2);
  for (j = 1; j <= t2; j++)
    {
      int j;
      int answer;
      int min = 10000000;
      int sum = 0;
      int xor = 0;
      scanf ("%d", &answer);
      for (j = 0; j < answer; j++)
	{
	  int d;
	  scanf ("%d", &d);
	  sum += d;
	  xor ^= d;
	  if (d < min)
	    min = d;
	}
      printf ("Case #%d: ", j);
      if (xor == 0)
	printf ("%d\n", sum - min);
      else
	printf ("NO\n");
    }
  return 0;
}
