#include <stdio.h>
int main()
{
  int first_iteration;
  int Tcases;
  scanf("%d", &Tcases);
  int cases;
  for (cases = 0; cases != Tcases; cases++)
  {
    int min = 0x7FFFFFFF;
    int N;
    scanf("%d", &N);
    int cur;
    int tot = 0;
    int sum = 0;
    while (N--)
    {
      scanf("%d", &cur);
      tot ^= cur;
      min = cur < min ? cur : min;
      sum += cur;
    }

    printf("Case #%d: ", cases + 1);
    if (tot)
    {
      printf("NO\n");
    }
    else
    {
      printf("%d\n", sum - min);
    }

  }

  return 0;
}


