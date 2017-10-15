#include <stdio.h>
void solve()
{
  int first_iteration;
  double best = 1e100;
  double tid;
  int d;
  int n;
  int d2;
  int f;
  scanf("%d %d", &d, &n);
  while (n--)
  {
    scanf("%d %d", &d2, &f);
    tid = (d - d2) / ((double) f);
    if (best > (d / tid))
      best = d / tid;

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


