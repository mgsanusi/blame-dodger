#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  int k;
  int a;
  int b;
  int i;
  double r;
  double x;
  double p;
  double d;
  double tmp;
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    scanf("%d%d", &a, &b);
    p = 1.0;
    r = 2.0 + b;
    for (i = 1; i <= a; i++)
    {
      scanf("%lf", &d);
      p = p * d;
      tmp = (((b + a) + 1) - (i * 2)) + ((1 - p) * (b + 1));
      r = r < tmp ? r : tmp;
    }

    printf("Case #%d: %.6lf\n", k, r);
  }

  return 0;
}


