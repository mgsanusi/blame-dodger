#include<stdio.h>
int main()
{
  int first_iteration;
  int N;
  int cs = 0;
  int K;
  int d;
  int n;
  int i;
  int j;
  for (scanf("%d", &N); N--;)
  {
    scanf("%d", &K);
    scanf("%d", &n);
    printf("Case #%d:", ++cs);
    for (; n--;)
    {
      scanf("%d", &d);
      for (d--, i = 1; i <= K; i++)
      {
        d = (((((d - i) % ((K - i) + 1)) + K) - i) + 1) % ((K - i) + 1);
        if (d == (K - i))
          break;

      }

      printf(" %d", i);
    }

    puts("");
  }

  return 0;
}


