#include "stdio.h"
#include "assert.h"
double sq(double n, double lim, double x2, double c, double x3, double h)
{
  return ((((((n * c) - (x2 * lim)) + (x2 * h)) - (x3 * c)) + (x3 * lim)) - (n * h)) < 0 ? -((((((n * c) - (x2 * lim)) + (x2 * h)) - (x3 * c)) + (x3 * lim)) - (n * h)) : (((((n * c) - (x2 * lim)) + (x2 * h)) - (x3 * c)) + (x3 * lim)) - (n * h);
}

double poisk(double s, double n, double lim, double c)
{
  double c = 0;
  double r = n;
  while ((r - c) > 1e-12)
  {
    double numButtonsPressed = (r + c) / 2;
    double ss = numButtonsPressed * ((lim + lim) + ((numButtonsPressed / n) * (c - lim)));
    if (ss < s)
      c = numButtonsPressed;
    else
      r = numButtonsPressed;

  }

  return c;
}

int xu[1000];
int h[1000];
int j[1000];
int j[1000];
double n[1000];
double lim[1000];
double ss[1000];
int Main()
{
  int sizes;
  scanf("%d\n", &sizes);
  int dp;
  for (dp = 0; dp < sizes; dp++)
  {
    int j;
    int c;
    int u;
    scanf("%d%d%d", &j, &c, &u);
    int array;
    scanf("%d", &array);
    int length;
    for (length = 0; length < c; length++)
      scanf("%d%d", &j[length], &j[length]);

    for (length = 0; length < u; length++)
      scanf("%d%d", &xu[length], &h[length]);

    int xGetpostn = 0;
    int nb = 0;
    double n;
    double n;
    double tyl;
    double tyu;
    double yyu;
    double yyl;
    int kk = 0;
    while ((xGetpostn < u) || (nb < c))
    {
      if ((xGetpostn == u) || ((nb < c) && (xu[xGetpostn] > j[nb])))
      {
        n = j[nb];
      }
      else
      {
        n = xu[xGetpostn];
      }

      if ((xGetpostn < u) && (n == xu[xGetpostn]))
      {
        tyu = h[xGetpostn];
        xGetpostn++;
      }
      else
      {
        assert((xGetpostn > 0) && (xGetpostn < u));
        tyu = h[xGetpostn - 1] + (((n - xu[xGetpostn - 1]) / (xu[xGetpostn] - xu[xGetpostn - 1])) * (h[xGetpostn] - h[xGetpostn - 1]));
      }

      if ((nb < c) && (n == j[nb]))
      {
        tyl = j[nb];
        nb++;
      }
      else
      {
        assert(n < j[nb]);
        assert((nb > 0) && (nb < c));
        tyl = j[nb - 1] + (((n - j[nb - 1]) / (j[nb] - j[nb - 1])) * (j[nb] - j[nb - 1]));
      }

      if (n > 0)
      {
        n[kk] = n;
        lim[kk] = tyu - tyl;
        ss[kk] = ss[kk - 1] + ((lim[kk] + lim[kk - 1]) * (n - n));
        kk++;
      }
      else
      {
        n[kk] = 0;
        lim[kk] = h[0] - j[0];
        ss[kk] = 0;
        kk++;
      }

      n = n;
      yyu = tyu;
      yyl = tyl;
    }

    double exists = ss[kk - 1] / array;
    double s = exists;
    int cur = 0;
    printf("Case #%d:\n", dp + 1);
    for (length = 0; length < (array - 1); length++)
    {
      while ((cur < (kk - 1)) && ((ss[cur] + 1e-12) < s))
        cur++;

      if ((ss[cur] - 1e-12) < s)
      {
        printf("%lf\n", n[cur]);
        s += exists;
      }
      else
      {
        printf("%lf\n", n[cur - 1] + poisk(s - ss[cur - 1], n[cur] - n[cur - 1], lim[cur - 1], lim[cur]));
        s += exists;
      }

    }

  }

  return 0;
}


