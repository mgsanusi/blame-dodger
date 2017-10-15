#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Main()
{
  int j;
  int num;
  int x_getlong;
  int i;
  int k;
  int y;
  int z;
  int dx;
  int done;
  int ri;
  int vx;
  int cp;
  int j;
  int sdx;
  int sdy;
  int sdz;
  double count;
  double cases;
  double i_t;
  double fdx;
  double fdy;
  double fdz;
  double v;
  double dmin;
  double s;
  scanf("%d", &j);
  for (x_getlong = 1; x_getlong <= j; ++x_getlong)
  {
    scanf("%d", &num);
    vx = (cp = (j = (sdx = (sdy = (sdz = 0)))));
    for (i = 0; i < num; ++i)
    {
      scanf("%d %d %d %d %d %d", &k, &y, &z, &dx, &done, &ri);
      vx += k;
      sdx += dx;
      cp += y;
      sdy += done;
      j += z;
      sdz += ri;
    }

    count = vx / ((double) num);
    fdx = sdx / ((double) num);
    cases = cp / ((double) num);
    fdy = sdy / ((double) num);
    i_t = j / ((double) num);
    fdz = sdz / ((double) num);
    v = ((fdx * fdx) + (fdy * fdy)) + (fdz * fdz);
    s = 1;
    s = 0;
    if (fabs(v) > 0.000000001)
    {
      s = (-(((count * fdx) + (cases * fdy)) + (i_t * fdz))) / (((fdx * fdx) + (fdy * fdy)) + (fdz * fdz));
      if (s < 0)
      {
        s = 1;
        s = 0;
      }

    }

    count += s * fdx;
    cases += s * fdy;
    i_t += s * fdz;
    dmin = sqrt(((count * count) + (cases * cases)) + (i_t * i_t));
    printf("Case #%d: %.8f %.8f\n", x_getlong, dmin, fabs(s));
  }

  return 0;
}


