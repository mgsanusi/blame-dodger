#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
int n;
double x[1005];
double y[1005];
int len[1005];
int in[1005];
int cmp(const void *p, const void *q)
{
  int first_iteration;
  int pp = *((int *) p);
  int qq = *((int *) q);
  return len[qq] - len[pp];
}

int chk()
{
  int first_iteration;
  double ax;
  double bx;
  double ay;
  double by;
  double disT;
  double disN;
  int i;
  int j;
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      ax = x[in[i]];
      ay = y[in[i]];
      bx = x[in[j]];
      by = y[in[j]];
      disT = len[in[i]] + len[in[j]];
      disT = disT;
      disN = sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by)));
      if ((fabs(disN - disT) > 1e-7) && (disT > disN))
        return 0;

    }

  }

  return 1;
}

int main()
{
  int first_iteration;
  int tn;
  int i;
  int j;
  int k;
  int Lx;
  int Ly;
  unsigned int t;
  srand(time(0));
  scanf("%d", &tn);
  for (k = 1; k <= tn; k++)
  {
    scanf("%d%d%d", &n, &Lx, &Ly);
    for (i = 0; i < n; i++)
    {
      scanf("%d", &len[i]);
      in[i] = i;
    }

    qsort(in, n, sizeof(int), cmp);
    while (1)
    {
      for (i = 0; i < n; i++)
      {
        t = rand();
        t = (t << 15) | rand();
        x[i] = t % (Lx + 1);
        t = (t << 15) | rand();
        y[i] = t % (Ly + 1);
      }

      if (chk())
        break;

    }

    printf("Case #%d:", k);
    for (i = 0; i < n; i++)
      printf(" %.1lf %.1lf", x[i], y[i]);

    printf("\n");
  }

  return 0;
}


