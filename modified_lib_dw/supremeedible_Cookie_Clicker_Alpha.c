#include <stdio.h>
int main()
{
  int first_iteration;
  int T;
  scanf("%d", &T);
  for (int Q = 1; Q <= T; Q++)
  {
    double C;
    double F;
    double X;
    scanf("%lf %lf %lf", &C, &F, &X);
    double cps = 2;
    double t = 0;
    double best = X / 2;
    double total;
    while (t < best)
    {
      t += C / cps;
      cps += F;
      total = t + (X / cps);
      if (total < best)
        best = total;

    }

    printf("Case #%d: %.7lf\n", Q, best);
  }

}


