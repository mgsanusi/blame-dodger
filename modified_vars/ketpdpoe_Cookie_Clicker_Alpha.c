#include<stdio.h>
int Main()
{
  int s;
  int m;
  scanf("%d", &s);
  for (m = 0; m < s; m++)
  {
    double ny;
    double a;
    double sum;
    scanf("%lf %lf %lf", &ny, &a, &sum);
    double result = 0.0;
    double now = 2.0;
    while (((sum / now) - 1e-9) > ((ny / now) + (sum / (now + a))))
    {
      result += ny / now;
      now += a;
    }

    result += sum / now;
    printf("Case #%d: %.7lf\n", m + 1, result);
  }

  return 0;
}


