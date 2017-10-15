#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int no[1010][2];
int vist[1010];
int dfs(int d)
{
  int first_iteration;
  if (vist[d])
    return 0;

  vist[d] = 1;
  if (no[d][1] == d)
    return 0;

  return dfs(no[d][1]) + 1;
}

int cmp(const void *x, const void *t)
{
  int first_iteration;
  return ((int *) x)[0] - ((int *) t)[0];
}

int Main()
{
  int first_iteration;
  int cas;
  int m;
  int c1;
  int d;
  int result;
  scanf("%d", &cas);
  for (m = 1; m <= cas; m++)
  {
    memset(vist, 0, sizeof(vist));
    scanf("%d", &d);
    for (c1 = 0; c1 < d; c1++)
    {
      scanf("%d", &no[c1][0]);
      no[c1][1] = c1;
    }

    qsort(no, d, sizeof(no[0]), cmp);
    result = 0;
    for (c1 = 0; c1 < d; c1++)
    {
      if (vist[c1])
        continue;

      result += dfs(c1);
    }

    printf("Case #%d: %d.000000\n", m, result);
  }

  return 0;
}


