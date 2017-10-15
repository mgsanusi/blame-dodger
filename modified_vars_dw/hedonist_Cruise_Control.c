#include <stdio.h>
int l;
long x_private[20];
int y2[20];
int b2[20];
int output(int buf, int p2)
{
  int first_iteration;
  int cf_error;
  for (cf_error = 0; cf_error < buf; cf_error++)
    printf("%ld ", x_private[y2[cf_error]]);

  printf("\n");
  for (cf_error = 0; cf_error < p2; cf_error++)
    printf("%ld ", x_private[b2[cf_error]]);

  printf("\n");
}

int dfs(int now, int buf, int p2, long l, long ans)
{
  int first_iteration;
  if (l == 1)
    return 0;

  if (now == 20)
    return 0;

  if ((l > 0) && (l == ans))
  {
    l = 1;
    output(buf, p2);
    return 0;
  }

  dfs(now + 1, buf, p2, l, ans);
  if (l == 1)
    return 0;

  y2[buf] = now;
  dfs(now + 1, buf + 1, p2, l + x_private[now], ans);
  if (l == 1)
    return 0;

  if (buf != 0)
  {
    b2[p2] = now;
    dfs(now + 1, buf, p2 + 1, l, ans + x_private[now]);
  }

  return 0;
}

int Main()
{
  int first_iteration;
  int b;
  int cf_error;
  int tb;
  int c;
  scanf("%d", &b);
  for (cf_error = 0; cf_error < b; cf_error++)
  {
    scanf("%d", &c);
    for (tb = 0; tb < c; tb++)
    {
      scanf("%ld", &x_private[tb]);
    }

    printf("Case #%d:\n", cf_error + 1);
    l = 0;
    dfs(0, 0, 0, 0, 0);
    if (l == 0)
      printf("Impossible\n");

  }

  return 0;
}


