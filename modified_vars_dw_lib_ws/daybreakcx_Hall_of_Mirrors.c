#include <stdio.h>
int sum;
int disT;
int i;
int j;
int t;
int m;
int b;
int v[500];
int
Main ()
{
  int first_iteration;
  scanf ("%d", &disT);
  for (sum = 1; sum <= disT; ++sum)
    {
      printf ("Case #%d:", sum);
      scanf ("%d", &m);
      for (i = (b = 0); i < m; ++i)
	{
	  scanf ("%d", &v[i]);
	  b += v[i];
	}
      for (i = (j = (t = 0)); i < m; ++i)
	if ((m * v[i]) >= (b << 1))
	  {
	    ++j;
	    t += v[i];
	  }
      for (i = 0; i < m; ++i)
	{
	  if ((v[i] * m) >= (b << 1))
	    printf (" 0");
	  else
	    printf (" %lf",
		    (((100.0 * ((2 * b) - t)) / (m - j)) / b) -
		    ((100.0 * v[i]) / b));
	}
      printf ("\n");
    }
  return 0;
}
