#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  int x;
  int T;
  int i;
  int j;
  int k;
  int m;
  int N;
  int J;
  long long a;
  scanf("%u", &T);
  for (x = 1; x <= T; x++)
  {
    scanf("%d %d", &N, &J);
    printf("Case #%d:\n", x);
    for (i = 0; i < J; i++)
    {
      printf("1");
      for (m = i, j = 0; j < ((N / 2) - 2); j++)
      {
        printf("%d", m & 1);
        m /= 2;
      }

      printf("11");
      for (m = i, j = 0; j < ((N / 2) - 2); j++)
      {
        printf("%d", m & 1);
        m /= 2;
      }

      printf("1 ");
      for (k = 2; k <= 10; k++)
      {
        a = 1;
        m = i;
        for (j = 0; j < ((N / 2) - 2); j++)
        {
          a = (a * k) + (m & 1);
          m /= 2;
        }

        a = (a * k) + 1;
        printf(" %lld", a);
      }

      printf("\n");
    }

  }

}


