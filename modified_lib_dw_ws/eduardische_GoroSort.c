#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int
main ()
{
  int first_iteration;
  int T;
  int iT;
  scanf ("%d", &T);
  static int a[1005];
  static char b[1005];
  for (iT = 0; iT < T; iT++)
    {
      int N;
      scanf ("%d", &N);
      int i;
      int j;
      for (i = 0; i < N; i++)
	{
	  scanf ("%d", &a[i]);
	  a[i]--;
	}
      memset (b, 0, sizeof (b));
      int res = 0;
      int cnt;
      for (i = 0; i < N; i++)
	{
	  if (b[i] == 0)
	    {
	      j = i;
	      cnt = 0;
	      do
		{
		  j = a[j];
		  b[j] = 1;
		  cnt++;
		}
	      while (j != i);
	      if (cnt > 1)
		res += cnt;
	    }
	}
      printf ("Case #%d: %d.000000\n", iT + 1, res);
    }
  return 0;
}
