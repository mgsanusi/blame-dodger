#include <stdio.h>
double sum[3000];
int
main (void)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int t;
  scanf ("%d", &t);
  for (i = 1; i <= t; i++)
    {
      double c;
      double f;
      double x;
      double ans;
      scanf ("%lf %lf %lf", &c, &f, &x);
      sum[0] = 0.0;
      for (j = 1; j < 3000; j++)
	sum[j] = sum[j - 1] + (c / (2 + (f * (j - 1))));
      for (j = 0; j < 3000; j++)
	sum[j] += x / (2 + (f * j));
      ans = 1e200;
      for (j = 0; j < 3000; j++)
	ans = ans < sum[j] ? ans : sum[j];
      printf ("Case #%d: %.7f\n", i, ans);
    }
  return 0;
}
