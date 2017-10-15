#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  int T;
  int N;
  int i;
  scanf("%d", &T);
  for (i = 1; i <= T; i++)
  {
    scanf("%d", &N);
    int j;
    int temp;
    double ans = 0.0;
    for (j = 1; j <= N; j++)
    {
      scanf("%d", &temp);
      if (temp != j)
        ans += 1.0;

    }

    printf("Case #%d: %.6lf\n", i, ans);
  }

  return 0;
}


