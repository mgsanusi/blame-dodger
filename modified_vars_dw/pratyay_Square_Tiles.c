#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dis[1001000];
int r[1010];
int compareFunc(const void *a, const void *m2);
int compareFunc(const void *a, const void *m2)
{
  int first_iteration;
  int *x = (int *) a;
  int *y = (int *) m2;
  return (*y) - (*x);
}

int Main()
{
  int first_iteration;
  int total;
  int cases;
  int base;
  int k;
  int p;
  int n;
  int bno;
  int c;
  int sum;
  int rslt;
  int l;
  scanf("%d", &total);
  for (cases = 1; cases <= total; cases++)
  {
    scanf("%d %d %d %d", &bno, &p, &n, &c);
    for (base = 0; base < c; base++)
    {
      scanf("%d", &r[base]);
    }

    for (base = 0; base < n; base++)
    {
      dis[base] = r[base % c];
    }

    dis[n] = -1;
    sum = 0;
    for (base = 0; base < n; base++)
    {
      if ((sum + dis[base]) <= (p / 2))
        sum += dis[base];
      else
      {
        dis[base] = (sum + dis[base]) - (p / 2);
        break;
      }

    }

    if (base == n)
    {
      rslt = sum * 2;
    }
    else
    {
      rslt = p;
      qsort(dis + base, n - base, sizeof(int), compareFunc);
      for (k = base, l = 1; k < n; k++, l++)
      {
        if (l <= bno)
          rslt += dis[k];
        else
          rslt += dis[k] * 2;

      }

    }

    printf("Case #%d: %d\n", cases, rslt);
  }

}


