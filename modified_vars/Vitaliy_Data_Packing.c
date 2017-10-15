#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int c[1000];
int t[1000];
void clear(void)
{
  int i;
  int y;
  assert(scanf("%d", &y) == 1);
  for (i = 0; i < y; i++)
  {
    assert(scanf("%d", &c[i]) == 1);
  }

  int res = 0;
  for (i = 0; i < y; i++)
  {
    int p = -1;
    int yyl;
    for (yyl = 0; yyl < (y - i); yyl++)
    {
      if ((p == (-1)) || (c[p] > c[yyl]))
      {
        p = yyl;
      }

    }

    if (p < (((y - i) - p) - 1))
    {
      res += p;
    }
    else
    {
      res += ((y - i) - p) - 1;
    }

    memmove(c + p, (c + p) + 1, 4 * (((y - i) - p) - 1));
  }

  printf(" %d\n", res);
}

int Main()
{
  int kk;
  assert(scanf("%d", &kk) == 1);
  int buffer;
  for (buffer = 0; buffer < kk; buffer++)
  {
    printf("Case #%d:", buffer + 1);
    clear();
  }

  return 0;
}


