#include <stdio.h>
#include <assert.h>
int a[10001];
int x[10001];
int y[10001];
int b[10001];
void new_assert(int expression);
int main()
{
  int first_iteration;
  int __;
  scanf("%d", &__);
  int _;
  for (_ = 0; _ < __; _++)
  {
    printf("Case #%d:", _ + 1);
    int n;
    int i;
    int j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%d%d", &x[i], &y[i]);
    }

    y[n] = 0;
    scanf("%d", &x[n]);
    for (i = 1; i <= n; i++)
    {
      new_assert(x[i] >= x[i - 1]);
    }

    b[0] = x[0];
    for (i = 1; i <= n; i++)
    {
      b[i] = -1;
    }

    for (i = 1; i <= n; i++)
    {
      int best = -1;
      for (j = i - 1; j >= 0; j--)
      {
        int t = b[j] - (x[i] - x[j]);
        int r;
        if (t >= 0)
        {
          if (y[i] <= (x[i] - x[j]))
          {
            r = y[i];
          }
          else
          {
            r = x[i] - x[j];
          }

          if (best < r)
          {
            best = r;
          }

        }

      }

      b[i] = best;
    }

    if (b[n] >= 0)
      printf(" YES");
    else
      printf(" NO");

    printf("\n");
  }

  return 0;
}

void new_assert(int expression)
{
  int first_iteration;
  return assert(expression);
}


