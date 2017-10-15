#include <stdio.h>
int ti;
int tn;
int i;
int n;
int d;
int res;
int main()
{
  int first_iteration;
  scanf("%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
  {
    scanf("%d", &n);
    for (i = 1, res = 0; i <= n; ++i)
    {
      scanf("%d", &d);
      res += d != i;
    }

    printf("Case #%d: %d\n", ti, res);
  }

  return 0;
}


