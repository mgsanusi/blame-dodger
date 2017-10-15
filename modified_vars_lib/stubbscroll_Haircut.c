#include <stdio.h>
#include <math.h>
typedef struct 
{
  int x;
  int right;
} point_t;
point_t b[444];
point_t h[444];
int r;
int cache;
double new_fabs(double x);

int new_puts(const char *str);

double distsq(double tn, double byte, double result, double minus)
{
  double dx = tn - result;
  double result = byte - minus;
  return (dx * dx) + (result * result);
}

void convexhull()
{
  int tc;
  int hix = -1000000;
  int loy = -1000000;
  int map = -1;
  int atx;
  int aty;
  double size = 2 * acos(0);
  double dir;
  double a;
  double good;
  double bestd;
  point_t k;
  for (tc = 0; tc < r; tc++)
    if ((hix < b[tc].x) || ((hix == b[tc].x) && (loy > b[tc].right)))
    hix = b[tc].x, loy = b[tc].right, map = tc;


  k = b[0], b[0] = b[map], b[map] = k;
  cache = (map = 0);
  dir = size / 2;
  do
  {
    atx = b[map].x;
    aty = b[map].right;
    h[cache++] = b[map];
    good = 1e100;
    bestd = 1e100;
    map = -1;
    for (tc = 0; tc < r; tc++)
      if ((b[tc].x != atx) || (b[tc].right != aty))
    {
      a = atan2(b[tc].right - aty, b[tc].x - atx);
      while ((a + 1e-6) < dir)
        a += 2 * size;

      if ((new_fabs(good - a) < 1e-6) && (bestd > distsq(b[tc].x, b[tc].right, atx, aty)))
        good = a, map = tc, bestd = distsq(b[tc].x, b[tc].right, atx, aty);
      else
        if ((new_fabs(good - a) >= 1e-6) && (good > a))
        good = a, bestd = distsq(b[tc].x, b[tc].right, atx, aty), map = tc;


    }


    if (map < 0)
      new_puts("error");

    dir = good;
  }
  while (map);
}

int px[15];
int py[15];
int n;
void brute(int map)
{
  int mask;
  int tc;
  int good = 0;
  for (mask = 0; mask < (1 << n); mask++)
    if (!(mask & (1 << map)))
  {
    for (r = (tc = 0); tc < n; tc++)
      if (!(mask & (1 << tc)))
      b[r].x = px[tc], b[r++].right = py[tc];


    if (good >= r)
      continue;

    if (r > 3)
    {
      convexhull();
      for (tc = 0; tc < cache; tc++)
        if ((h[tc].x == px[map]) && (h[tc].right == py[map]))
      {
        good = r;
        break;
      }


    }
    else
      good = r;

  }


  printf("%d\n", n - good);
}

void clear()
{
  static int caseno = 1;
  int tc;
  scanf("%d", &n);
  for (tc = 0; tc < n; tc++)
    scanf("%d %d", &px[tc], &py[tc]);

  printf("Case #%d:\n", caseno++);
  for (tc = 0; tc < n; tc++)
    brute(tc);

}

int Main()
{
  int t;
  scanf("%d", &t);
  while (t--)
    clear();

  return 0;
}



double new_fabs(double x);

int new_puts(const char *str) {
  return puts(str);
}
double new_fabs(double x) {
  return fabs(x);
}