#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void doubleIntSort(double d[], int m[], int s)
{
  int first_iteration;
  int i;
  int j;
  int r;
  double k1;
  double k2;
  double t;
  if (s <= 1)
    return;

  k1 = (d[0] + d[s - 1]) / 2.0;
  k2 = k1 + 1e-10;
  k1 -= 1e-10;
  i = -1;
  j = s;
  for (;;)
  {
    while (d[++i] < k1)
      ;

    while (d[--j] > k2)
      ;

    if (i >= j)
      break;

    t = d[i];
    d[i] = d[j];
    d[j] = t;
    r = m[i];
    m[i] = m[j];
    m[j] = r;
  }

  doubleIntSort(d, m, i);
  doubleIntSort((d + j) + 1, (m + j) + 1, (s - j) - 1);
}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  double walk;
  double run;
  double run_time;
  double len;
  double st[1200];
  double ed[1200];
  double ksk[1200];
  double go_len[1200];
  double go_speed[1200];
  double rest;
  double need;
  double val[1200];
  int ind[1200];
  double res;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%lf%lf%lf", &len, &walk, &run);
    scanf("%lf%d", &run_time, &n);
    for (i = 0; i < n; i++)
      scanf("%lf%lf%lf", st + i, ed + i, ksk + i);

    rest = len;
    for (i = 0; i < n; i++)
      rest -= ed[i] - st[i];

    for (i = 0; i < n; i++)
    {
      go_len[i] = ed[i] - st[i];
      go_speed[i] = ksk[i] + walk;
    }

    go_len[n] = rest;
    go_speed[n] = walk;
    n++;
    for (i = 0; i < n; i++)
      val[i] = go_speed[i], ind[i] = i;

    doubleIntSort(val, ind, n);
    res = 0;
    for (i = 0; i < n; i++)
    {
      k = ind[i];
      rest = go_len[k];
      need = rest / ((go_speed[k] + run) - walk);
      if (need > run_time)
        need = run_time;

      res += need;
      rest -= ((go_speed[k] + run) - walk) * need;
      run_time -= need;
      need = rest / go_speed[k];
      res += need;
    }

    printf("Case #%d: %.10lf\n", ++count, res);
  }

  return 0;
}


