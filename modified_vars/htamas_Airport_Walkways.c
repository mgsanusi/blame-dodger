#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  int speed;
  int len;
} walkway;
walkway w[1001];
static int cmp(const void *p1, const void *b)
{
  return ((walkway *) p1)->speed - ((walkway *) b)->speed;
}

int Main(int argc, char **argv)
{
  int num;
  int ch;
  int base;
  int x;
  int n;
  int m;
  int ar_versions;
  int r;
  int res;
  int akhir;
  int to;
  double run;
  double time;
  double result;
  scanf("%d", &num);
  for (ch = 1; ch <= num; ++ch)
  {
    scanf("%d %d %d %d %d", &base, &x, &n, &m, &ar_versions);
    for (to = 1; to <= ar_versions; ++to)
    {
      scanf("%d %d %d", &r, &res, &akhir);
      w[to].len = res - r;
      w[to].speed = akhir;
      base -= res - r;
    }

    w[0].len = base;
    w[0].speed = 0;
    qsort(w, ar_versions + 1, sizeof(walkway), cmp);
    run = n;
    time = 0;
    for (to = 0; to <= ar_versions; ++to)
    {
      if (run > 0)
      {
        result = ((double) w[to].len) / (((double) w[to].speed) + n);
        if (run >= result)
        {
          run -= result;
          time += result;
        }
        else
        {
          time += run + ((((double) w[to].len) - (run * (((double) w[to].speed) + n))) / (((double) w[to].speed) + x));
          run = 0;
        }

      }
      else
      {
        result = ((double) w[to].len) / (((double) w[to].speed) + x);
        time += result;
      }

    }

    printf("Case #%d: %.6lf\n", ch, time);
  }

  return 0;
}


