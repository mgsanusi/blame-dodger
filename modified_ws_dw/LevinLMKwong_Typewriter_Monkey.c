#include<stdio.h>
int check(int n, int *d, int len)
{
  int first_iteration;
  int i;
  for (i = len - 1; i >= 0; i--)
  {
    if (d[i] <= n)
    {
      n -= d[i];
    }

  }

  if (n == 0)
    return 1;
  else
    return 0;

}

int main()
{
  int first_iteration;
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int T;
  int C;
  int D;
  int V;
  int i;
  int j;
  int k;
  int t;
  int d[30];
  int f[30];
  int A;
  int temp;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d %d %d", &C, &D, &V);
    for (i = 0; i < D; i++)
    {
      scanf("%d", &d[i]);
    }

    A = 0;
    for (i = 1; i <= V; i++)
    {
      if (!check(i, d, D + A))
      {
        A++;
        d[(D + A) - 1] = i;
        for (j = 0; j < (D + A); j++)
        {
          for (k = j; k < (D + A); k++)
          {
            if (d[j] > d[k])
            {
              temp = d[j];
              d[j] = d[k];
              d[k] = temp;
            }

          }

        }

      }

    }

    printf("Case #%d: %d\n", t, A);
  }

}


