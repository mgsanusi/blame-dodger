#include <stdio.h>
#include <stdlib.h>
int
main ()
{
  int first_iteration;
  int x;
  int T;
  int i;
  int y;
  int N;
  int found[10];
  int count;
  scanf ("%d", &T);
  for (x = 1; x <= T; x++)
    {
      scanf ("%d", &N);
      if (N == 0)
	{
	  printf ("Case #%d: INSOMNIA\n", x);
	  continue;
	}
      for (i = 0; i < 10; i++)
	found[i] = 0;
      count = 10;
      for (y = N;; y += N)
	{
	  for (i = y; i != 0; i /= 10)
	    {
	      if (found[i % 10] == 0)
		{
		  if ((--count) == 0)
		    break;
		  found[i % 10] = 1;
		}
	    }
	  if (count == 0)
	    break;
	}
      printf ("Case #%d: %d\n", x, y);
    }
}
