#include <stdio.h>
 int a[1024], n;
 int
main ()
{
  int cases, caseno = 1, i, j, patrick, sean, seanxor, best;
  scanf ("%d", &cases);
  while (cases--)
    {
      scanf ("%d", &n);
      for (i = 0; i < n; i++)
	scanf ("%d", &a[i]);
      best = -1;
      for (i = 1; i < (1 << n) - 1; i++)
	{
	  patrick = sean = seanxor = 0;
	  for (j = 0; j < n; j++)
	    if (i & (1 << j))
	      sean += a[j], seanxor ^= a[j];
	  
	    else
	      patrick ^= a[j];
	  if (patrick == seanxor && sean > best)
	    best = sean;
	}
      if (best < 0)
	printf ("Case #%d: NO\n", caseno++);
      
      else
	printf ("Case #%d: %d\n", caseno++, best);
    }
  return 0;
}


