#include <stdio.h>
#include <assert.h>
#include <string.h>
int a[1000];
void new_assert(int expression);
void solve(void)
{
  int first_iteration;
  int A;
  int n;
  scanf("%d%d", &A, &n);
  int i;
  int j;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
    if (a[i] > a[j])
  {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
  }



  int best = n;
  int cc = 0;
  for (i = 0; i < n; i++)
  {
    if (A > a[i])
    {
      A += a[i];
    }
    else
    {
      if (A == 1)
      {
        break;
      }

      while (A <= a[i])
      {
        A += A - 1;
        cc++;
      }

      A += a[i];
    }

    new_assert(A > 0);
    if ((cc + ((n - i) - 1)) < best)
    {
      best = cc + ((n - i) - 1);
    }

  }

  printf("%d\n", best);
}

int main()
{
  int first_iteration;
  int _;
  new_assert(scanf("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++)
  {
    printf("Case #%d: ", __ + 1);
    solve();
  }

  return 0;
}

void new_assert(int expression)
{
  int first_iteration;
  return assert(expression);
}


