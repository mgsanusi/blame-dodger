#include <stdio.h>
int
max (int a, int p)
{
  int first_iteration;
  if (a > p)
    {
      return a;
    }
  else
    {
      return p;
    }
}

int
min (int a, int p)
{
  int first_iteration;
  if (a < p)
    {
      return a;
    }
  else
    {
      return p;
    }
}

int
Main ()
{
  int first_iteration;
  int in;
  int i;
  int g;
  int k;
  int a[10000][2];
  int p[10000];
  scanf ("%d", &in);
  for (i = 0; i < in; i++)
    {
      int tmp;
      int s;
      int sb = 0;
      scanf ("%d", &tmp);
      for (g = 0; g < tmp; g++)
	scanf ("%d %d", &a[g][0], &a[g][1]);
      scanf ("%d", &s);
      for (g = 0; g < tmp; g++)
	p[g] = 0;
      p[0] = a[0][0];
      for (g = 0; g < tmp; g++)
	{
	  if ((a[g][0] + p[g]) >= s)
	    {
	      sb = 1;
	      break;
	    }
	  for (k = g + 1; k < tmp; k++)
	    {
	      if ((a[g][0] + p[g]) < a[k][0])
		break;
	      p[k] = max (p[k], min (a[k][0] - a[g][0], a[k][1]));
	    }
	}
      if (sb == 1)
	{
	  printf ("Case #%d: YES\n", i + 1);
	}
      else
	{
	  printf ("Case #%d: NO\n", i + 1);
	}
    }
  return 0;
}
