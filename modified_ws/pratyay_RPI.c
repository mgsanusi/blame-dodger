#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char sh[110][110];
long double wp[110][110];
long double owp[110];
long double oowp[110];
main ()
{
  int total, n, i, j, k, played, won, f1, f2;
  long double up, down, rpi;
  scanf ("%d", &total);
  for (i = 1; i <= total; i++)
    {
      printf ("Case #%d:\n", i);
      scanf ("%d", &n);
      for (j = 0; j < n; j++)
	{
	  scanf ("%s", sh[j]);
	  //printf("%s\n",sh[j]);
	  played = 0;
	  won = 0;
	  for (k = 0; k < n; k++)
	    {
	      if (sh[j][k] != '.')
		played++;
	      if (sh[j][k] == '1')
		won++;
	    }
	  for (k = 0; k < n; k++)
	    {
	      if (sh[j][k] != '.')
		f1 = 1;
	      else
		f1 = 0;
	      if (sh[j][k] == '1')
		f2 = 1;
	      else
		f2 = 0;
	      wp[j][k] =
		((long double) (won - f2)) / ((long double) (played - f1));
	    }

	}
      for (j = 0; j < n; j++)
	{
	  up = 0.0;
	  f2 = 0;
	  for (k = 0; k < n; k++)
	    {
	      if (sh[j][k] != '.')
		{
		  up += wp[k][j];
		  f2++;
		}
	    }
	  owp[j] = up / (long double) (f2);
	}
      for (j = 0; j < n; j++)
	{
	  up = 0.0;
	  f2 = 0;
	  for (k = 0; k < n; k++)
	    {
	      if (sh[j][k] != '.')
		{
		  up += owp[k];
		  f2++;
		}
	    }
	  oowp[j] = up / (long double) (f2);
	  rpi = 0.25 * oowp[j] + 0.5 * owp[j] + 0.25 * wp[j][j];
	  printf ("%.10Lf\n", rpi);
	}
    }

}
