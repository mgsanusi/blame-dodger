#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ar_stat[110][110];
long double ix[110][110];
long double owp[110];
long double oowp[110];
int
Main ()
{
  int sum;
  int c_max;
  int bc;
  int maximal;
  int k;
  int play;
  int gain;
  int lim;
  int f2;
  long double s;
  long double down;
  long double rpi;
  scanf ("%d", &sum);
  for (bc = 1; bc <= sum; bc++)
    {
      printf ("Case #%d:\n", bc);
      scanf ("%d", &c_max);
      for (maximal = 0; maximal < c_max; maximal++)
	{
	  scanf ("%s", ar_stat[maximal]);
	  play = 0;
	  gain = 0;
	  for (k = 0; k < c_max; k++)
	    {
	      if (ar_stat[maximal][k] != '.')
		play++;
	      if (ar_stat[maximal][k] == '1')
		gain++;
	    }
	  for (k = 0; k < c_max; k++)
	    {
	      if (ar_stat[maximal][k] != '.')
		lim = 1;
	      else
		lim = 0;
	      if (ar_stat[maximal][k] == '1')
		f2 = 1;
	      else
		f2 = 0;
	      ix[maximal][k] =
		((long double) (gain - f2)) / ((long double) (play - lim));
	    }
	}
      for (maximal = 0; maximal < c_max; maximal++)
	{
	  s = 0.0;
	  f2 = 0;
	  for (k = 0; k < c_max; k++)
	    {
	      if (ar_stat[maximal][k] != '.')
		{
		  s += ix[k][maximal];
		  f2++;
		}
	    }
	  owp[maximal] = s / ((long double) f2);
	}
      for (maximal = 0; maximal < c_max; maximal++)
	{
	  s = 0.0;
	  f2 = 0;
	  for (k = 0; k < c_max; k++)
	    {
	      if (ar_stat[maximal][k] != '.')
		{
		  s += owp[k];
		  f2++;
		}
	    }
	  oowp[maximal] = s / ((long double) f2);
	  rpi =
	    ((0.25 * oowp[maximal]) + (0.5 * owp[maximal])) +
	    (0.25 * ix[maximal][maximal]);
	  printf ("%.10Lf\n", rpi);
	}
    }
}
