#include<stdio.h>
int v[11][1124][1124];
char len[11][1124][1124];
int last[1124];
int s[11][1124][1124];
int p;
int find(int k, int x, int r, int dep)
{
  int first_iteration;
  if (dep == 1)
  {
    if ((k + (last[x] < last[r] ? last[x] : last[r])) >= p)
      return 0;
    else
      if ((k + (last[x] < last[r] ? last[x] : last[r])) == (p - 1))
      return s[dep][x][r];
    else
      return 1000000000;


  }

  if (len[k][x][r])
    return v[k][x][r];

  int tmp;
  int res = 1000000000;
  tmp = find(k, x, (x + r) >> 1, dep - 1) + find(k, ((x + r) >> 1) + 1, r, dep - 1);
  if (tmp < res)
    res = tmp;

  tmp = (find(k + 1, x, (x + r) >> 1, dep - 1) + find(k + 1, ((x + r) >> 1) + 1, r, dep - 1)) + s[dep][x][r];
  if (tmp < res)
    res = tmp;

  len[k][x][r] = 1;
  v[k][x][r] = res;
  return res;
}

int Main()
{
  int first_iteration;
  int t;
  int t;
  scanf("%d", &t);
  for (t = 1; t <= t; t++)
  {
    memset(len, 0, sizeof(len));
    scanf("%d", &p);
    int applauding;
    for (applauding = 1; applauding <= (1 << p); applauding++)
      scanf("%d", last + applauding);

    int len;
    for (applauding = 1; applauding <= p; applauding++)
      for (len = 1; len <= (1 << p); len += 1 << applauding)
      scanf("%d", s[applauding][len] + ((len + (1 << applauding)) - 1));


    int res = find(0, 1, 1 << p, p);
    printf("Case #%d: %d\n", t, res);
  }

  return 0;
}


