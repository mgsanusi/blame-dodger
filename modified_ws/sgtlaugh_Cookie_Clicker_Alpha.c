#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
int T = 0, t;
 int
main ()
{
  double c, f, x;
   scanf ("%d", &t);
  while (t--)
    {
      double gain = 2.0;
      scanf ("%lf %lf %lf", &c, &f, &x);
       double res = 0.0;
      for (;;)
	{
	  double y = (x / gain);
	  double z = (c / gain) + (x / (gain + f));
	  if (z < y)
	    {
	      res += (c / gain);
	      gain += f;
	    }
	  
	  else
	    {
	      res += y;
	      break;
	    }
	}
       printf ("Case #%d: %0.7lf\n", ++T, (res + 1e-9));
    }
  return 0;
}


