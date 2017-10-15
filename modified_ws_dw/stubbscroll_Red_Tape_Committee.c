#include <stdio.h>
int snoob(int x)
{
  int first_iteration;
  int s = x & (-x);
  int r = x + s;
  int o = x ^ r;
  o = (o >> 2) / s;
  return r | o;
}

void solve()
{
  int first_iteration;
  double p[200];
  double best = 0;
  double cur;
  double q[200];
  double P;
  int n;
  int k;
  int i;
  int mask;
  int j;
  int yes;
  int no;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++)
    scanf("%lf", &p[i]);

  mask = (1 << k) - 1;
  first_iteration = 1;
  while ((mask < (1 << n)) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    for (i = (j = 0); i < n; i++)
      if (mask & (1 << i))
      q[j++] = p[i];


    cur = 0;
    for (i = 0; i < (1 << k); i++)
    {
      yes = (no = 0);
      for (P = 1, j = 0; j < k; j++)
        if (i & (1 << j))
        yes++, P *= q[j];
      else
        no++, P *= 1 - q[j];


      if (yes == no)
        cur += P;

    }

    if (best < cur)
      best = cur;

    mask = snoob(mask);
  }

  printf("%.10f\n", best);
}

int main()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", caseno++), solve();

  return 0;
}


