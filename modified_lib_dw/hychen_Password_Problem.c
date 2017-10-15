#include<stdio.h>
double correct[100001];
double firsterr[100001];
int main(int argc, char *argv[])
{
  int first_iteration;
  int a;
  int b;
  int e;
  int f;
  int typed;
  int total;
  double expect;
  double d;
  scanf("%d", &f);
  for (e = 1; e <= f; e++)
  {
    scanf("%d%d", &typed, &total);
    d = 1;
    for (a = 0; a < typed; a++)
    {
      scanf("%lf", correct + a);
      firsterr[a] = d;
      d *= correct[a];
    }

    firsterr[typed] = d;
    expect = total + 2;
    for (b = 0; b <= typed; b++)
    {
      d = ((((2 * b) + total) - typed) + 1) + ((1 - firsterr[typed - b]) * (1 + total));
      if (expect > d)
        expect = d;

    }

    printf("Case #%d: %lf\n", e, expect);
  }

  return 0;
}


