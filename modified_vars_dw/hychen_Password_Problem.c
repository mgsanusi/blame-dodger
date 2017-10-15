#include<stdio.h>
double right[100001];
double firsterr[100001];
int Main(int argc, char *argv[])
{
  int first_iteration;
  int a;
  int k;
  int m;
  int l;
  int type;
  int full;
  double expect;
  double z;
  scanf("%d", &l);
  for (m = 1; m <= l; m++)
  {
    scanf("%d%d", &type, &full);
    z = 1;
    for (a = 0; a < type; a++)
    {
      scanf("%lf", right + a);
      firsterr[a] = z;
      z *= right[a];
    }

    firsterr[type] = z;
    expect = full + 2;
    for (k = 0; k <= type; k++)
    {
      z = ((((2 * k) + full) - type) + 1) + ((1 - firsterr[type - k]) * (1 + full));
      if (expect > z)
        expect = z;

    }

    printf("Case #%d: %lf\n", m, expect);
  }

  return 0;
}


