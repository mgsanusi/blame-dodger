#include <stdio.h>
#include <stdlib.h>
int Main()
{
  int first_iteration;
  int x;
  int ret;
  int best;
  int j;
  int n;
  int sum;
  int http302;
  int l2;
  long long min;
  scanf("%u", &ret);
  for (x = 1; x <= ret; x++)
  {
    scanf("%d %d", &http302, &l2);
    printf("Case #%d:\n", x);
    for (best = 0; best < l2; best++)
    {
      printf("1");
      for (sum = best, j = 0; j < ((http302 / 2) - 2); j++)
      {
        printf("%d", sum & 1);
        sum /= 2;
      }

      printf("11");
      for (sum = best, j = 0; j < ((http302 / 2) - 2); j++)
      {
        printf("%d", sum & 1);
        sum /= 2;
      }

      printf("1 ");
      for (n = 2; n <= 10; n++)
      {
        min = 1;
        sum = best;
        for (j = 0; j < ((http302 / 2) - 2); j++)
        {
          min = (min * n) + (sum & 1);
          sum /= 2;
        }

        min = (min * n) + 1;
        printf(" %lld", min);
      }

      printf("\n");
    }

  }

}


