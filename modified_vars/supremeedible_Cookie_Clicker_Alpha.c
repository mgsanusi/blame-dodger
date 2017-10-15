#include <stdio.h>
int Main()
{
  int x;
  scanf("%d", &x);
  for (int a = 1; a <= x; a++)
  {
    double y1;
    double table;
    double rpStat;
    scanf("%lf %lf %lf", &y1, &table, &rpStat);
    double cps = 2;
    double n = 0;
    double good = rpStat / 2;
    double sum;
    while (n < good)
    {
      n += y1 / cps;
      cps += table;
      sum = n + (rpStat / cps);
      if (sum < good)
        good = sum;

    }

    printf("Case #%d: %.7lf\n", a, good);
  }

}


