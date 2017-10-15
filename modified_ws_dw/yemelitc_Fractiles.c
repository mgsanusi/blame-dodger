#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  int x;
  int T;
  int i;
  int K;
  int C;
  int S;
  unsigned long long y;
  unsigned long long kc;
  scanf("%u", &T);
  for (x = 1; x <= T; x++)
  {
    scanf("%d %d %d", &K, &C, &S);
    for (kc = 1, i = 1; i < C; i++)
      kc *= K;

    printf("Case #%d:", x);
    for (y = 0, i = 0; i < S; i++)
    {
      printf(" %llu", y + 1);
      y += kc;
    }

    printf("\n");
  }

}


