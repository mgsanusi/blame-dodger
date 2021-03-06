#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
long w;
long l;
double r[1000];
double x[1000];
double y[1000];
int idx[1000];
int sort(int h, int d)
{
  int i;
  int o;
  int mididx;
  double midr;
  if (h < d)
  {
    i = h;
    o = d;
    midr = r[i];
    mididx = idx[i];
    while (i < o)
    {
      while ((i < o) && (r[o] < midr))
        o--;

      r[i] = r[o];
      idx[i] = idx[o];
      if (i < o)
        i++;

      while ((i < o) && (r[i] > midr))
        i++;

      r[o] = r[i];
      idx[o] = idx[i];
      if (i < o)
        o--;

    }

    r[i] = midr;
    idx[i] = mididx;
    sort(h, i - 1);
    sort(i + 1, d);
  }

  return 0;
}

int input()
{
  int i;
  scanf("%d %ld %ld", &n, &w, &l);
  for (i = 0; i < n; i++)
  {
    scanf("%lf", &r[i]);
    idx[i] = i;
  }

  sort(0, n - 1);
  return 0;
}

int output()
{
  int i;
  double cur[1000];
  double cSum[1000];
  for (i = 0; i < n; i++)
  {
    cur[idx[i]] = x[i];
    cSum[idx[i]] = y[i];
  }

  for (i = 0; i < n; i++)
    printf(" %.2lf %.2lf", cur[i], cSum[i]);

  printf("\n");
  return 0;
}

int work()
{
  int i;
  int o;
  int p;
  int f;
  while (1)
  {
    f = 1;
    for (i = 0; i < n; i++)
    {
      p = 0;
      while (p < 10000)
      {
        x[i] = ((rand() * 32767) + rand()) % (w + 1);
        y[i] = ((rand() * 32767) + rand()) % (l + 1);
        for (o = 0; o < i; o++)
          if ((((x[i] - x[o]) * (x[i] - x[o])) + ((y[i] - y[o]) * (y[i] - y[o]))) < ((r[i] + r[o]) * (r[i] + r[o])))
        {
          f = 0;
          break;
        }


        if (f == 1)
          break;

        p++;
      }

      if (f == 0)
        break;

    }

    if (f > 0)
      break;

  }

  return 0;
}

int Main()
{
  long t;
  long i;
  srand(time(0));
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    input();
    work();
    printf("Case #%d:", i + 1);
    output();
  }

  return 0;
}


