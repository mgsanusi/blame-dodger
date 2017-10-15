#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int new_puts(const char *str);
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int res;
  int now;
  int ok;
  int a[1200];
  int b[1200];
  int alr[1200];
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    printf("Case #%d: ", ++count);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d%d", a + i, b + i);

    for (i = 0; i < n; i++)
      alr[i] = 0;

    res = 0;
    now = 0;
    for (;;)
    {
      if (now == (2 * n))
        break;

      ok = 0;
      for (i = 0; i < n; i++)
        if ((alr[i] != 2) && (b[i] <= now))
      {
        res++;
        now += 2 - alr[i];
        alr[i] = 2;
        ok = 1;
      }


      if (ok)
        continue;

      k = -1;
      for (i = 0; i < n; i++)
        if ((alr[i] == 0) && (a[i] <= now))
      {
        if (k == (-1))
        {
          k = i;
          continue;
        }

        if (b[i] > b[k])
          k = i;

      }


      if (k == (-1))
      {
        res = -1;
        break;
      }

      alr[k] = 1;
      res++;
      now++;
    }

    if (res == (-1))
      new_puts("Too Bad");
    else
      printf("%d\n", res);

  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


