#include<stdio.h>
double correct[100001];
double firsterr[100001];
int Main(int argc, char *argv[])
{
  int first_iteration;
  int t;
  int q;
  int size;
  int str;
  int type;
  int total;
  double expect;
  double d;
  scanf("%d", &str);
  for (size = 1; size <= str; size++)
  {
    scanf("%d%d", &type, &total);
    d = 1;
    for (t = 0; t < type; t++)
    {
      scanf("%lf", correct + t);
      firsterr[t] = d;
      d *= correct[t];
    }

    firsterr[type] = d;
    expect = total + 2;
    for (q = 0; q <= type; q++)
    {
      d = ((((2 * q) + total) - type) + 1) + ((1 - firsterr[type - q]) * (1 + total));
      if (expect > d)
        expect = d;

    }

    printf("Case #%d: %lf\n", size, expect);
  }

  return 0;
}


