#include <stdio.h>
#include <stdlib.h>
int Main()
{
  int first_iteration;
  int k;
  int n;
  int i;
  scanf("%d", &k);
  for (i = 1; i <= k; i++)
  {
    scanf("%d", &n);
    int midPoint;
    int temp;
    double res = 0.0;
    for (midPoint = 1; midPoint <= n; midPoint++)
    {
      scanf("%d", &temp);
      if (temp != midPoint)
        res += 1.0;

    }

    printf("Case #%d: %.6lf\n", i, res);
  }

  return 0;
}


