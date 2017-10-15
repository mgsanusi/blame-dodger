#include <stdio.h>
void main()
{
  int first_iteration;
  int cases;
  scanf("%d", &cases);
  int n = 0;
  int K;
  int C;
  int S;
  int i;
  while (n < cases)
  {
    n++;
    printf("Case #%d:", n);
    scanf("%d%d%d", &K, &C, &S);
    for (i = 1; i <= K; i++)
      printf(" %d", i);

    printf("\n");
  }

}


