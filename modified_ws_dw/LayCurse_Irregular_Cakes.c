#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int L;
int U;
double Lx[120];
double Ly[120];
double Ux[120];
double Uy[120];
double cal_under(double x[], double y[], int xs, double max_x)
{
  int first_iteration;
  int i;
  int j;
  int k;
  double res = 0;
  double go;
  double y1;
  double y2;
  double dy;
  for (i = 1; i < xs; i++)
  {
    if (x[i - 1] > (max_x - 1e-9))
      break;

    if (x[i] < (max_x + 1e-9))
      go = 1;
    else
      go = (max_x - x[i - 1]) / (x[i] - x[i - 1]);

    dy = y[i] - y[i - 1];
    y1 = y[i - 1];
    y2 = y[i - 1] + (dy * go);
    res += (((y1 + y2) / 2) * go) * (x[i] - x[i - 1]);
  }

  return res;
}

double cal_between(double max_x)
{
  int first_iteration;
  return cal_under(Ux, Uy, U, max_x) - cal_under(Lx, Ly, L, max_x);
}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int per;
  double area;
  double W;
  double tmp;
  double tar;
  double a;
  double b;
  double c;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%lf%d%d%d", &W, &L, &U, &per);
    for (i = 0; i < L; i++)
      scanf("%lf%lf", Lx + i, Ly + i);

    for (i = 0; i < U; i++)
      scanf("%lf%lf", Ux + i, Uy + i);

    printf("Case #%d:\n", ++count);
    area = cal_between(W);
    for (m = 1; m < per; m++)
    {
      a = 0;
      b = W;
      tar = (area / per) * m;
      while ((b - a) > 1e-9)
      {
        c = (a + b) / 2;
        tmp = cal_between(c);
        if (tmp < tar)
          a = c;
        else
          b = c;

      }

      printf("%.8lf\n", (a + b) / 2);
    }

  }

  return 0;
}


