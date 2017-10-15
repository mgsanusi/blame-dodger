#include <stdio.h>
int t;
int r;
int c;
int d;
char w[505][505];
int
main ()
{
  int first_iteration;
  int t_count;
  scanf ("%d", &t_count);
  for (t = 1; t <= t_count; t++)
    {
      scanf ("%d %d %d", &r, &c, &d);
      int i;
      int j;
      for (i = 0; i < r; i++)
	scanf ("%s", w[i]);
      int ans = 0;
      for (i = 0; i < r; i++)
	for (j = 0; j < c; j++)
	  {
	    int rangex = (r - i) < (c - j) ? r - i : c - j;
	    int range;
	    for (range = 1; range <= rangex; range++)
	      {
		int r_sum = 0;
		int c_sum = 0;
		int ki;
		int kj;
		for (ki = i; ki < (i + range); ki++)
		  for (kj = j; kj < (j + range); kj++)
		    {
		      if (((ki == i) || (ki == ((i + range) - 1)))
			  && ((kj == j) || (kj == ((j + range) - 1))))
			;
		      else
			{
			  r_sum +=
			    (((2 * ki) - i) -
			     ((i + range) - 1)) * ((d + w[ki][kj]) - '0');
			  c_sum +=
			    (((2 * kj) - j) -
			     ((j + range) - 1)) * ((d + w[ki][kj]) - '0');
			}
		    }
		if ((r_sum == 0) && (c_sum == 0))
		  ans = ans > range ? ans : range;
	      }
	  }
      printf ("Case #%d: ", t);
      if (ans >= 3)
	printf ("%d\n", ans);
      else
	printf ("IMPOSSIBLE\n");
    }
  return 0;
}
