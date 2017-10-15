#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int ab(int x)
{
  int first_iteration;
  if (x < 0)
    return -x;

  return x;
}

int ix[120][300];
int d[120];
int first;
int i;
int h;
int t;
int clear(int st, int bef)
{
  int first_iteration;
  int i;
  int cfError;
  int c;
  int res = 1000000000;
  int add;
  int tmp;
  if (ix[st][bef] >= 0)
    return ix[st][bef];

  if (st == t)
    return ix[st][bef] = 0;

  for (i = 0; i < 256; i++)
    if (ab(bef - d[st]) > ab(i - d[st]))
  {
    add = ab(bef - i) - h;
    if (add < 0)
      add = 0;

    c = (clear(st, i) + i) + add;
    if (res > c)
      res = c;

  }


  for (i = 0; i < 256; i++)
  {
    add = ab(bef - i) - h;
    if (add < 0)
      add = 0;

    tmp = ab(i - d[st]);
    c = (clear(st + 1, i) + add) + tmp;
    if (res > c)
      res = c;

  }

  c = clear(st + 1, bef) + first;
  if (res > c)
    res = c;

  return ix[st][bef] = res;
}

int Main()
{
  int first_iteration;
  int i;
  int cfError;
  int c;
  int b;
  int now;
  int res;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d%d%d", &first, &i, &h, &t);
    for (i = 0; i < t; i++)
      scanf("%d", d + i);

    for (i = 0; i < (t + 1); i++)
      for (cfError = 0; cfError < 256; cfError++)
      ix[i][cfError] = -1;


    res = 1000000000;
    for (i = 0; i < (t + 1); i++)
    {
      c = clear(i, d[i]) + (i * first);
      if (res > c)
        res = c;

    }

    printf("Case #%d: %d\n", ++count, res);
  }

  return 0;
}


