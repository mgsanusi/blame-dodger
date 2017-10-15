#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int x;
  int num;
} node[300];
int d;
int c;
int new_puts(const char *str);
int check(int l);
int main()
{
  int first_iteration;
  int t;
  int Case;
  int i;
  int j;
  int cc;
  int l;
  int m;
  int r;
  int OK;
  scanf("%d", &Case);
  for (t = 1; t <= Case; ++t)
  {
    scanf("%d %d", &c, &d);
    d = d << 1;
    for (i = 0; i < c; ++i)
    {
      scanf("%d %d", &node[i].x, &node[i].num);
      node[i].x *= 2;
    }

    l = 0, r = (OK = 100000000);
    while (l <= r)
    {
      m = (l + r) / 2;
      cc = check(m);
      if (cc)
      {
        l = m + 1;
      }
      else
      {
        if (OK > m)
          OK = m;

        r = m - 1;
      }

    }

    printf("Case #%d: %.1lf\n", t, ((double) OK) / 2);
  }

  return 0;
}

int new_puts(const char *str);
int check(int l)
{
  int first_iteration;
  int i;
  int j;
  int left = (node[0].x - l) + d;
  for (i = 1; i < node[0].num; ++i)
  {
    if ((node[0].x - l) > left)
    {
      left = (node[0].x - l) + d;
    }
    else
      if ((node[0].x - l) <= left)
    {
      if ((left - node[0].x) > l)
        return 1;

      left = left + d;
    }
    else
    {
      return 1;
    }


  }

  for (i = 1; i < c; ++i)
  {
    for (j = 0; j < node[i].num; ++j)
    {
      if ((node[i].x - l) > left)
      {
        left = (node[i].x - l) + d;
      }
      else
        if ((node[i].x - l) <= left)
      {
        if ((left - node[i].x) > l)
          return 1;

        left = left + d;
      }
      else
      {
        return 1;
      }


    }

  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


