#include <stdio.h>
#include <string.h>
int
main ()
{
  int t, n, tc = 1, i, j, temp;
  char DAT[15];
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d", &n);
      if (!n)
	printf ("Case #%d: INSOMNIA\n", tc++);
      else
	{
	  memset (DAT, 0, 15 * sizeof (char));
	  i = 1;
	  while (1)
	    {
	      temp = i * n;
	      while (temp)
		{
		  DAT[temp % 10] = 1;
		  temp /= 10;
		}
	      for (j = 0; j < 10; ++j)
		{
		  if (!DAT[j])
		    {
		      j = -1;
		      break;
		    }
		}
	      if (j > -1)
		{
		  printf ("Case #%d: %d\n", tc++, i * n);
		  break;
		}
	      ++i;
	    }
	}
    }
  return 0;
}
