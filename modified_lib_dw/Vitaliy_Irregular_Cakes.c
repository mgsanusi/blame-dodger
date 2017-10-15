#include "stdio.h"
#include "assert.h"
void new_assert(int expression);
double sq(double x1, double y1, double x2, double y2, double x3, double y3)
{
  int first_iteration;
  return ((((((x1 * y2) - (x2 * y1)) + (x2 * y3)) - (x3 * y2)) + (x3 * y1)) - (x1 * y3)) < 0 ? -((((((x1 * y2) - (x2 * y1)) + (x2 * y3)) - (x3 * y2)) + (x3 * y1)) - (x1 * y3)) : (((((x1 * y2) - (x2 * y1)) + (x2 * y3)) - (x3 * y2)) + (x3 * y1)) - (x1 * y3);
}

double poisk(double s, double x, double y1, double y2)
{
  int first_iteration;
  double l = 0;
  double r = x;
  while ((r - l) > 1e-12)
  {
    double t = (r + l) / 2;
    double ss = t * ((y1 + y1) + ((t / x) * (y2 - y1)));
    if (ss < s)
      l = t;
    else
      r = t;

  }

  return l;
}

int xu[1000];
int yu[1000];
int xl[1000];
int yl[1000];
double x1[1000];
double y1[1000];
double ss[1000];
int main()
{
  int first_iteration;
  int tn;
  scanf("%d\n", &tn);
  int tt;
  for (tt = 0; tt < tn; tt++)
  {
    int w;
    int l;
    int u;
    scanf("%d%d%d", &w, &l, &u);
    int G;
    scanf("%d", &G);
    int i;
    for (i = 0; i < l; i++)
      scanf("%d%d", &xl[i], &yl[i]);

    for (i = 0; i < u; i++)
      scanf("%d%d", &xu[i], &yu[i]);

    int p1 = 0;
    int p2 = 0;
    double x;
    double xx;
    double tyl;
    double tyu;
    double yyu;
    double yyl;
    int cc = 0;
    while ((p1 < u) || (p2 < l))
    {
      if ((p1 == u) || ((p2 < l) && (xu[p1] > xl[p2])))
      {
        x = xl[p2];
      }
      else
      {
        x = xu[p1];
      }

      if ((p1 < u) && (x == xu[p1]))
      {
        tyu = yu[p1];
        p1++;
      }
      else
      {
        new_assert((p1 > 0) && (p1 < u));
        tyu = yu[p1 - 1] + (((x - xu[p1 - 1]) / (xu[p1] - xu[p1 - 1])) * (yu[p1] - yu[p1 - 1]));
      }

      if ((p2 < l) && (x == xl[p2]))
      {
        tyl = yl[p2];
        p2++;
      }
      else
      {
        new_assert(x < xl[p2]);
        new_assert((p2 > 0) && (p2 < l));
        tyl = yl[p2 - 1] + (((x - xl[p2 - 1]) / (xl[p2] - xl[p2 - 1])) * (yl[p2] - yl[p2 - 1]));
      }

      if (x > 0)
      {
        x1[cc] = x;
        y1[cc] = tyu - tyl;
        ss[cc] = ss[cc - 1] + ((y1[cc] + y1[cc - 1]) * (x - xx));
        cc++;
      }
      else
      {
        x1[cc] = 0;
        y1[cc] = yu[0] - yl[0];
        ss[cc] = 0;
        cc++;
      }

      xx = x;
      yyu = tyu;
      yyl = tyl;
    }

    double st = ss[cc - 1] / G;
    double s = st;
    int cur = 0;
    printf("Case #%d:\n", tt + 1);
    for (i = 0; i < (G - 1); i++)
    {
      while ((cur < (cc - 1)) && ((ss[cur] + 1e-12) < s))
        cur++;

      if ((ss[cur] - 1e-12) < s)
      {
        printf("%lf\n", x1[cur]);
        s += st;
      }
      else
      {
        printf("%lf\n", x1[cur - 1] + poisk(s - ss[cur - 1], x1[cur] - x1[cur - 1], y1[cur - 1], y1[cur]));
        s += st;
      }

    }

  }

  return 0;
}

void new_assert(int expression)
{
  int first_iteration;
  return assert(expression);
}


