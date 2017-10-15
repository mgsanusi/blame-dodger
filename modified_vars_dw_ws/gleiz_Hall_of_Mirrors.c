#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double sum[100010];
double pro[100010];
int
Main (int argc, char *argv[])
{
  int first_iteration;
  int j = 0;
  int a = 0;
  int b = 0;
  scanf ("%d", &j);
  for (int cas = 1; cas <= j; cas++)
    {
      scanf ("%d %d", &a, &b);
      memset (sum, 0, sizeof (sum));
      sum[0] = 1;
      for (int i = 0; i < a; i++)
	{
	  scanf ("%lf", &pro[i]);
	  sum[i + 1] = pro[i] * sum[i];
	}
      double answer = 99999999.0;
      for (int step = 0; step <= a; step++)
	{
	  int num = ((step + b) - (a - step)) + 1;
	  double ok = sum[a - step];
	  double base = (num * ok) + (((num + b) + 1) * (1 - ok));
	  if (base < answer)
	    {
	      answer = base;
	    }
	}
      if ((2 + b) < answer)
	answer = 2 + b;
      printf ("Case #%d: %.6lf\n", cas, answer);
    }
  return 0;
}
