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
int sort(int h, int t)
{
  int first_iteration;
  int i;
  int j;
  int mididx;
  double midr;
  if (h < t)
  {
    i = h;
    j = t;
    midr = r[i];
    mididx = idx[i];
    while (i < j)
    {
      while ((i < j) && (r[j] < midr))
        j--;

      r[i] = r[j];
      idx[i] = idx[j];
      if (i < j)
        i++;

      while ((i < j) && (r[i] > midr))
        i++;

      r[j] = r[i];
      idx[j] = idx[i];
      if (i < j)
        j--;

    }

    r[i] = midr;
    idx[i] = mididx;
    sort(h, i - 1);
    sort(i + 1, t);
  }

  return 0;
}

int input()
{
  int first_iteration;
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
  int first_iteration;
  int i;
  double xx[1000];
  double yy[1000];
  for (i = 0; i < n; i++)
  {
    xx[idx[i]] = x[i];
    yy[idx[i]] = y[i];
  }

  for (i = 0; i < n; i++)
    printf(" %.2lf %.2lf", xx[i], yy[i]);

  printf("\n");
  return 0;
}

int work()
{
  int first_iteration;
  int i;
  int j;
  int c;
  int f;
  while (1)
  {
    f = 1;
    for (i = 0; i < n; i++)
    {
      c = 0;
      while (c < 10000)
      {
        x[i] = ((rand() * 32767) + rand()) % (w + 1);
        y[i] = ((rand() * 32767) + rand()) % (l + 1);
        for (j = 0; j < i; j++)
          if ((((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j]))) < ((r[i] + r[j]) * (r[i] + r[j])))
        {
          f = 0;
          break;
        }


        if (f == 1)
          break;

        c++;
      }

      if (f == 0)
        break;

    }

    if (f > 0)
      break;

  }

  return 0;
}

int main()
{
  int first_iteration;
  long T;
  long i;
  srand(time(0));
  scanf("%d", &T);
  for (i = 0; i < T; i++)
  {
    input();
    work();
    printf("Case #%d:", i + 1);
    output();
  }

  return 0;
}


