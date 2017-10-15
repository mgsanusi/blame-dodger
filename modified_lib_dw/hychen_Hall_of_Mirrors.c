#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double new_sqrt(double x);
int gcd(int a, int b)
{
  int first_iteration;
  int c;
  if (a < 0)
    a = -a;

  if (b < 0)
    b = -b;

  while (b != 0)
  {
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

char room[32][32];
int raytrace(const int a, const int b, int x, int y, const int dist)
{
  int first_iteration;
  int path[128][2];
  int npath;
  int ix;
  int iy;
  int c;
  int d;
  int refx;
  int refy;
  double len;
  double px;
  double py;
  if (b == 0)
  {
    int c;
    for (c = 0; room[x + (c * a)][y] != '#'; c++)
      ;

    return ((c * 2) - 1) <= dist;
  }

  if (a == 0)
  {
    int c;
    for (c = 0; room[x][y + (c * b)] != '#'; c++)
      ;

    return ((c * 2) - 1) <= dist;
  }

  len = new_sqrt((a * a) + (b * b));
  npath = (a >= 0 ? a : -a) + (b >= 0 ? b : -b);
  if (((a % 2) != 0) && ((b % 2) != 0))
    npath--;

  px = (py = 0.5);
  ix = (iy = 0);
  for (c = 0; c < npath; c++)
  {
    double t1;
    double t2;
    int iscorner;
    t1 = ((ix + (a > 0)) - px) / a;
    t2 = ((iy + (b > 0)) - py) / b;
    path[c][0] = 0;
    path[c][1] = 0;
    if (((t1 - t2) < 1e-8) && ((t1 - t2) > (-1e-8)))
      iscorner = 1;
    else
      iscorner = 0;

    if ((iscorner == 1) && (((c * 2) + 1) != npath))
      fprintf(stderr, "corner\n");

    if (iscorner || (t1 < t2))
    {
      path[c][0] = a > 0 ? 1 : -1;
      if (iscorner == 0)
        py += (((ix + (a > 0)) - px) / a) * b;

      px = ix + (a > 0);
    }

    if (iscorner || (t1 > t2))
    {
      path[c][1] = b > 0 ? 1 : -1;
      if (iscorner == 0)
        px += (((iy + (b > 0)) - py) / b) * a;

      py = iy + (b > 0);
    }

    if ((path[c][0] == 0) && (path[c][1] == 0))
      fprintf(stderr, "t1t2error\n");

    ix += path[c][0];
    iy += path[c][1];
  }

  refx = (refy = 1);
  for (d = 1; (dist + 1e-5) >= (len * d); d++)
  {
    for (c = 0; c < npath; c++)
    {
      int dx;
      int dy;
      dx = path[c][0] * refx;
      dy = path[c][1] * refy;
      if ((dx != 0) && (dy != 0))
      {
        if (room[x + dx][y + dy] != '#')
          goto loopfinish;

        if ((room[x + dx][y] != '#') && (room[x][y + dy] != '#'))
          return 0;

      }

      if ((dx != 0) && (room[x + dx][y] == '#'))
      {
        dx = 0;
        refx = -refx;
      }

      if ((dy != 0) && (room[x][y + dy] == '#'))
      {
        dy = 0;
        refy = -refy;
      }

      loopfinish:
      x += dx;

      y += dy;
    }

    if (room[x][y] == 'X')
      return 1;

  }

  return 0;
}

int main(int argc, char *argv[])
{
  int first_iteration;
  int a;
  int b;
  int d;
  int e;
  int dist;
  int h;
  int w;
  int x;
  int y;
  int count;
  scanf("%d", &e);
  for (d = 1; d <= e; d++)
  {
    scanf("%d%d%d", &h, &w, &dist);
    x = (y = -1);
    for (a = 0; a < h; a++)
    {
      scanf("%s", room[a]);
      for (b = 0; (x == (-1)) && (b < w); b++)
      {
        if (room[a][b] != 'X')
          continue;

        x = a;
        y = b;
      }

    }

    count = 0;
    for (a = -dist; a <= dist; a++)
    {
      for (b = -dist; b <= dist; b++)
      {
        if ((a == 0) && (b == 0))
          continue;

        if (((a * a) + (b * b)) > (dist * dist))
          continue;

        if (gcd(a, b) != 1)
          continue;

        count += raytrace(a, b, x, y, dist);
      }

    }

    printf("Case #%d: %d\n", d, count);
  }

  return 0;
}

double new_sqrt(double x)
{
  int first_iteration;
  return sqrt(x);
}


