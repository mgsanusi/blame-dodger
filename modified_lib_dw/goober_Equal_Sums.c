#include <stdio.h>
#include <math.h>
double new_sqrt(double x);
double max(double a, double b)
{
  int first_iteration;
  return a > b ? a : b;
}

int main()
{
  int first_iteration;
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    printf("Case #%d:\n", t);
    int n;
    int A;
    double D;
    scanf("%lf %d %d", &D, &n, &A);
    double tm[n];
    double x[n];
    for (int i = 0; i < n; i++)
      scanf("%lf %lf", &tm[i], &x[i]);

    tm[n - 1] = tm[n - 2] + (((D - x[n - 2]) / (x[n - 1] - x[n - 2])) * (tm[n - 1] - tm[n - 2]));
    x[n - 1] = D;
    for (int cas = 0; cas < A; cas++)
    {
      double a;
      scanf("%lf", &a);
      double st = 0;
      for (int i = 0; i < n; i++)
        st = max(st, tm[i] - new_sqrt((2 * x[i]) / a));

      printf("%lf\n", st + sqrt((2 * D) / a));
    }

  }

  return 0;
}

double new_sqrt(double x)
{
  int first_iteration;
  return sqrt(x);
}

