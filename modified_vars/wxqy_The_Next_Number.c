#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
double sqr(double s2)
{
  return s2 * s2;
}

int dblcmp(double s2, double c)
{
  if (fabs(s2 - c) < 1e-9)
    return 0;
  else
    if (s2 < c)
    return -1;
  else
    return 1;


}

int Main()
{
  int gss_c_ma_mech_nego = 0;
  int v;
  int j;
  int s2;
  int c;
  int j;
  int best;
  int ene_end;
  int pd;
  int pass;
  for (scanf("%d", &v); v; v--)
  {
    gss_c_ma_mech_nego++;
    scanf("%d", &pass);
    double rangex = 0;
    double j = 0;
    double z = 0;
    double vx = 0;
    double vy = 0;
    double base = 0;
    for (j = 0; j < pass; j++)
    {
      scanf("%d%d%d%d%d%d", &s2, &c, &j, &best, &ene_end, &pd);
      rangex += s2;
      j += c;
      z += j;
      vx += best;
      vy += ene_end;
      base += pd;
    }

    double a;
    double kk;
    double j = ((vx * vx) + (vy * vy)) + (base * base);
    if (fabs(j) < 1e-9)
    {
      printf("Case #%d: %.8lf 0.00000000\n", gss_c_ma_mech_nego, sqrt((sqr(rangex) + sqr(j)) + sqr(z)) / pass);
      continue;
    }

    a = (-(((vx * rangex) + (vy * j)) + (base * z))) / j;
    if (dblcmp(a, 0) == (-1))
    {
      a = 0;
    }
    else
      if (dblcmp(((vx * rangex) + (vy * j)) + (base * z), 0) == 0)
      a = 0;


    kk = (sqr(rangex + (a * vx)) + sqr(j + (a * vy))) + sqr(z + (a * base));
    kk = sqrt(kk) / pass;
    printf("Case #%d: %.8lf %.8lf\n", gss_c_ma_mech_nego, kk, a);
  }

  return 0;
}


