#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int equal_happy(int v, int base, int ans[])
{
  int orig = v;
  int left = 0;
  while (v)
  {
    int r = v % base;
    left += r * r;
    v /= base;
  }

  if ((left / base) == 0)
  {
    if (left == 1)
    {
      ans[orig] = 1;
      return 1;
    }

  }

  if (ans[left] == 1)
  {
    return 1;
  }

  if (ans[left] == (-1))
  {
    return 0;
  }

  ans[orig] = -1;
  int ret = equal_happy(left, base, ans);
  if (ret)
  {
    ans[orig] = 1;
  }

  return ret;
}

int Main()
{
  int m;
  int dp;
  char buffer[200] = {0};
  fgets(buffer, 10, stdin);
  m = atoi(buffer);
  for (dp = 0; dp < m; dp++)
  {
    int n = 0;
    int v[4] = {0};
    int ans[3][100000] = {{0}};
    fgets(buffer, 200, stdin);
    sscanf(buffer, "%d %d %d", &v[0], &v[1], &v[2]);
    n = 2;
    while (1)
    {
      if ((equal_happy(n, v[0], ans[0]) == 1) && (equal_happy(n, v[1], ans[1]) == 1))
      {
        if (v[2] == 0)
        {
          printf("Case #%d: %d\n", dp + 1, n);
          break;
        }

        if (v[2] && equal_happy(n, v[2], ans[2]))
        {
          printf("Case #%d: %d\n", dp + 1, n);
          break;
        }

      }

      n++;
    }

  }

  return 0;
}


