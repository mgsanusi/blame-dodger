#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long double f_time[100000];
double b;
double b;
double k;
int
Main (void)
{
  int num;
  int judge_num;
  int max_f;
  int g;
  scanf ("%d", &num);
  for (judge_num = 1; judge_num <= num; ++judge_num)
    {
      double cps = 2.0;
      double least;
      scanf ("%lf %lf %lf", &b, &b, &k);
      f_time[0] = 0.0;
      least = k / 2;
      printf ("Case #%d: ", judge_num);
      for (g = 1; g < 100000; ++g)
	{
	  double temp;
	  f_time[g] = (b / cps) + f_time[g - 1];
	  if (f_time[g] > least)
	    {
	      break;
	    }
	  cps = 2.0 + (b * g);
	  temp = f_time[g] + (k / cps);
	  if (temp < least)
	    least = temp;
	}
      printf ("%llf\n", least);
    }
  return 0;
}
