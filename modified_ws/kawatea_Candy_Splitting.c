#include <stdio.h>
#include <stdlib.h>
 int
cmp (const void *a, const void *b) 
{
  return *(int *) a - *(int *) b;
}  int

main () 
{
  int t, i, j;
   scanf ("%d", &t);
   for (i = 0; i < t; i++)
    {
      int n;
      int a[1000];
      int b[20] = { 0 };
       scanf ("%d", &n);
       for (j = 0; j < n; j++)
	scanf ("%d", &a[j]);
       qsort (a, n, sizeof (int), cmp);
       for (j = 0; j < n; j++)
	{
	  int p = a[j], k = 0;
	   while (p)
	    {
	      if (p % 2 == 1)
		{
		  b[k] = (b[k] + 1) % 2;
		}
	       p /= 2;
	      k++;
	    }
	}
       printf ("Case #%d: ", i + 1);
       for (j = 0; j < 20; j++)
	{
	  if (b[j] > 0)
	    {
	      puts ("NO");
	      break;
	    }
	}
       if (j == 20)
	{
	  int s = 0;
	  for (j = 1; j < n; j++)
	    s += a[j];
	   printf ("%d\n", s);
	}
    }
   return 0;
}


