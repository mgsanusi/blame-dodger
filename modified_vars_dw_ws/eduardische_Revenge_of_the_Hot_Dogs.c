#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
  int fp_i;
  int q;
};
int
Main ()
{
  int first_iteration;
  int n;
  int i_t;
  scanf ("%d", &n);
  static char data[105][105];
  static struct node g[105];
  static double l[105];
  static double owp[105];
  static double oowp[105];
  for (i_t = 0; i_t < n; i_t++)
    {
      int n;
      scanf ("%d\n", &n);
      int ntest;
      int j;
      int mem;
      for (ntest = 0; ntest < n; ntest++)
	scanf ("%s\n", data[ntest]);
      for (ntest = 0; ntest < n; ntest++)
	{
	  memset (g, 0, sizeof (g));
	  for (j = 0; j < n; j++)
	    {
	      for (mem = 0; mem < n; mem++)
		{
		  if ((mem != ntest) && (data[j][mem] != '.'))
		    {
		      g[j].q++;
		      if (data[j][mem] == '1')
			g[j].fp_i++;
		    }
		}
	    }
	  l[ntest] = ((double) g[ntest].fp_i) / ((double) g[ntest].q);
	  owp[ntest] = 0.0;
	  int count = 0;
	  for (j = 0; j < n; j++)
	    {
	      if (data[ntest][j] != '.')
		{
		  owp[ntest] += ((double) g[j].fp_i) / ((double) g[j].q);
		  count++;
		}
	    }
	  owp[ntest] /= (double) count;
	}
      for (ntest = 0; ntest < n; ntest++)
	{
	  oowp[ntest] = 0.0;
	  int count = 0;
	  for (j = 0; j < n; j++)
	    {
	      if (data[ntest][j] != '.')
		{
		  oowp[ntest] += owp[j];
		  count++;
		}
	    }
	  oowp[ntest] /= (double) count;
	}
      printf ("Case #%d:\n", i_t + 1);
      for (ntest = 0; ntest < n; ntest++)
	printf ("%.10lf\n",
		((0.25 * l[ntest]) + (0.5 * owp[ntest])) +
		(0.25 * oowp[ntest]));
    }
  return 0;
}
