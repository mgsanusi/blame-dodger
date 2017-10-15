#include<stdio.h>
#include<stdlib.h>
int max(int ap, int l)
{
  int first_iteration;
  if (ap < l)
    return l;

  return ap;
}

int Main()
{
  int first_iteration;
  int n;
  int sum;
  int *p;
  int i;
  int w;
  int s;
  int k[2];
  int b;
  scanf("%d", &sum);
  for (i = 0; i < sum; i++)
  {
    scanf("%d", &n);
    p = (int *) malloc((sizeof(int)) * n);
    s = 0;
    for (w = 0; w < n; w++)
    {
      scanf("%d", p + w);
      s += p[w];
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

      for (w = 2; w < n; w++)
      {
        if (p[w] > p[k[1]])
        {
          if (p[w] > p[k[0]])
          {
            k[1] = k[0];
            k[0] = w;
          }
          else
            k[1] = w;

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
      for (w = 0; w < n; w++)
      {
        if (p[w] > 0)
        {
          if (b == 0)
          {
            printf("%c ", w + 'A');
            b = 1;
          }
          else
            printf("%c", w + 'A');

        }

      }

    }

    printf("\n");
    free(p);
  }

  return 0;
}


