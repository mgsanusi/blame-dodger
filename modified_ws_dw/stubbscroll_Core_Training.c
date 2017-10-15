#include <stdio.h>
int p;
int n;
int g[111];
int gm[4];
int min(int a, int b)
{
  int first_iteration;
  return a < b ? a : b;
}

void solve()
{
  int first_iteration;
  int i;
  int r = 0;
  int j;
  scanf("%d %d", &n, &p);
  for (i = 0; i < n; i++)
    scanf("%d", &g[i]);

  for (i = 0; i < p; i++)
    gm[i] = 0;

  for (i = 0; i < n; i++)
    gm[g[i] % p]++;

  r = gm[0];
  gm[0] = 0;
  if (p == 2)
  {
    j = gm[1] / 2;
    r += j;
    gm[1] -= j * 2;
  }
  else
    if (p == 3)
  {
    j = min(gm[1], gm[2]);
    r += j;
    gm[1] -= j;
    gm[2] -= j;
    j = gm[1] / 3;
    r += j;
    gm[1] -= j * 3;
    j = gm[2] / 3;
    r += j;
    gm[2] -= j * 3;
  }
  else
  {
    j = min(gm[1], gm[3]);
    r += j;
    gm[1] -= j;
    gm[3] -= j;
    j = gm[2] / 2;
    r += j;
    gm[2] -= j * 2;
    j = min(gm[1] / 2, gm[2]);
    r += j;
    gm[1] -= j * 2;
    gm[2] -= j;
    j = min(gm[3] / 2, gm[2]);
    r += j;
    gm[3] -= j * 2;
    gm[2] -= j;
    j = gm[1] / 4;
    r += j;
    gm[1] -= j * 4;
    j = gm[3] / 4;
    r += j;
    gm[3] -= j * 4;
  }


  for (i = 0; i < p; i++)
    if (gm[i])
  {
    r++;
    break;
  }


  printf("%d\n", r);
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


