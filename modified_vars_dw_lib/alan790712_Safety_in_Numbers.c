#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stddef.h>
int map[1001][1001];
int r;
char use[1001];
int tmp1;
int size[1001][1001];
void * new_memset(void *ptr, int value, int num);

int new_puts(const char *str);

int Main()
{
  int first_iteration;
  int Case = 0;
  int t;
  int ret;
  int pr;
  int min;
  int num;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &r);
    new_memset(map, 0, sizeof(map));
    new_memset(use, 0, sizeof(use));
    new_memset(size, 0, sizeof(size));
    for (ret = 1; ret <= r; ++ret)
    {
      scanf("%d", &num);
      while (num--)
      {
        scanf("%d", &pr);
        map[ret][pr] = 1;
        size[ret][pr] = 1;
      }

    }

    for (min = (tmp1 = 1); (min <= r) && tmp1; ++min)
    {
      for (ret = 1; (ret <= r) && tmp1; ++ret)
      {
        for (pr = 1; (pr <= r) && tmp1; ++pr)
        {
          if (size[ret][min] && size[min][pr])
          {
            ++size[ret][pr];
          }

          if (size[ret][pr] == 2)
            tmp1 = 0;

        }

      }

    }

    printf("Case #%d:", ++Case);
    if (!tmp1)
      new_puts(" Yes");
    else
      new_puts(" No");

  }

  return 0;
}



void * new_memset(void *ptr, int value, int num);

int new_puts(const char *str) {
  return puts(str);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}