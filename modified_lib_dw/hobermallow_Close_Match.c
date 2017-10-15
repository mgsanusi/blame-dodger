#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
void *new_malloc(size_t size);
int max(int x, int y)
{
  int first_iteration;
  if (x < y)
    return y;

  return x;
}

int main()
{
  int first_iteration;
  int n;
  int t;
  int *p;
  int i;
  int j;
  int s;
  int k[2];
  int b;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    scanf("%d", &n);
    p = (int *) new_malloc((sizeof(int)) * n);
    s = 0;
    for (j = 0; j < n; j++)
    {
      scanf("%d", p + j);
      s += p[j];
    }

    printf("Case #%d: ", i + 1);
    while ((s > 0) && (s != 3))
    {
      if (p[0] >= p[1])
      {
        k[0] = 0;
        k[1] = 1;
      }
      else
      {
        k[0] = 1;
        k[1] = 0;
      }

      for (j = 2; j < n; j++)
      {
        if (p[j] > p[k[1]])
        {
          if (p[j] > p[k[0]])
          {
            k[1] = k[0];
            k[0] = j;
          }
          else
            k[1] = j;

        }

      }

      p[k[0]]--;
      p[k[1]]--;
      s -= 2;
      printf("%c%c ", k[0] + 'A', k[1] + 'A');
    }

    if (s == 3)
    {
      b = 0;
      for (j = 0; j < n; j++)
      {
        if (p[j] > 0)
        {
          if (b == 0)
          {
            printf("%c ", j + 'A');
            b = 1;
          }
          else
            printf("%c", j + 'A');

        }

      }

    }

    printf("\n");
    free(p);
  }

  return 0;
}

void *new_malloc(size_t size)
{
  int first_iteration;
  return malloc(size);
}


