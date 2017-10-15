#include <stdio.h>
#include <stdlib.h>
int actIt(int line[], int from, int to)
{
  int i;
  int ret = 0;
  for (i = from; i <= to; i++)
  {
    if (line[i])
    {
      int c = (actIt(line, from, i - 1) + actIt(line, i + 1, to)) + (to - from);
      if ((!ret) || (c < ret))
      {
        ret = c;
      }

    }

  }

  return ret;
}

int Main()
{
  int n;
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    int line[10000] = {0};
    int r;
    int t;
    int bc;
    scanf("%d %d", &r, &t);
    for (bc = 0; bc < t; bc++)
    {
      int c;
      scanf("%d", &c);
      line[c - 1] = 1;
    }

    printf("Case #%d: %d\n", i + 1, actIt(line, 0, r - 1));
  }

  return 0;
}


