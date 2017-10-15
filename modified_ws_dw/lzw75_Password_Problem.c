#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  double *x;
  double *y;
  int num;
  int i;
  x = (double *) malloc((sizeof(double)) * 120000);
  y = (double *) malloc((sizeof(double)) * 120000);
  scanf("%d", &num);
  for (i = 0; i < num; i++)
  {
    int a;
    int b;
    int j;
    scanf("%d %d", &a, &b);
    for (j = 0; j < a; j++)
      scanf("%lf", &x[j]);

    y[0] = 1.0;
    for (j = 1; j <= a; j++)
    {
      y[j] = y[j - 1] * x[j - 1];
    }

    double best;
    double tmp;
    tmp = (b - a) + 1;
    tmp += (1 - y[a]) * (b + 1);
    best = tmp;
    for (j = 1; j <= a; j++)
    {
      tmp = y[a - j] * ((((j + b) - a) + 1) + j);
      tmp += (1 - y[a - j]) * ((((((j + b) - a) + 1) + j) + b) + 1);
      if (best > tmp)
        best = tmp;

    }

    if (best > (b + 2))
      best = b + 2;

    printf("Case #%d: %.10lf\n", i + 1, best);
  }

  free(y);
  free(x);
  return 0;
}


