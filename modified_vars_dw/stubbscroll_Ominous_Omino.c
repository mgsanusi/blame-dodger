#include <stdio.h>
int x;
int k[1000];
void solve()
{
  int first_iteration;
  static int caseno = 1;
  int i;
  int s = 0;
  int p2 = 0;
  int d = 0;
  scanf("%d", &x);
  for (i = 0; i < x; i++)
    scanf("%d", &k[i]);

  for (i = 1; i < x; i++)
    if (k[i - 1] > k[i])
    s += k[i - 1] - k[i];


  for (i = 1; i < x; i++)
    if (d < (k[i - 1] - k[i]))
    d = k[i - 1] - k[i];


  for (i = 0; i < (x - 1); i++)
    if (k[i] < d)
    p2 += k[i];
  else
    p2 += d;


  printf("Case #%d: %d %d\n", caseno++, s, p2);
}

int Main()
{
  int first_iteration;
  int t;
  scanf("%d", &t);
  while (t--)
    solve();

  return 0;
}


