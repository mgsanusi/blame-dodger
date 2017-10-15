#include<stdio.h>
#include<stdlib.h>
int t[10000][2];
void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int intcmp(const int *tmp, const int *b)
{
  int first_iteration;
  if (tmp[0] == b[0])
    return 0;

  return tmp[0] > b[0] ? 1 : -1;
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int n;
  int t;
  int tmp;
  int b;
  int size;
  int e;
  int arr;
  int rslt;
  scanf("%d", &arr);
  for (e = 1; e <= arr; e++)
  {
    scanf("%d%d", &n, &t);
    for (tmp = 0; tmp < n; tmp++)
    {
      scanf("%d", t[tmp] + 0);
      t[tmp][1] = 0;
    }

    new_qsort(t, n, (sizeof(int)) * 2, intcmp);
    rslt = 0;
    for (tmp = n - 1; tmp >= 0; tmp--)
    {
      if (t[tmp][1] == 1)
        continue;

      size = -1;
      for (b = tmp - 1; b >= 0; b--)
      {
        if (t[b][1] != 0)
          continue;

        if ((t[tmp][0] + t[b][0]) > t)
          continue;

        size = b;
        break;
      }

      if (size != (-1))
      {
        t[size][1] = (t[tmp][1] = 1);
      }

      rslt++;
    }

    printf("Case #%d: %d\n", e, rslt);
  }

  return 0;
}



void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}