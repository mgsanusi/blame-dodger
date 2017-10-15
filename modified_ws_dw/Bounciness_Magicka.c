#include <stdio.h>
#include <stdlib.h>
int C[1000];
int xor_array(int n)
{
  int first_iteration;
  int ret = 0;
  int i;
  for (i = 0; i < n; i++)
    ret = ret ^ C[i];

  return ret;
}

int main()
{
  int first_iteration;
  int T;
  int N;
  int i;
  int j;
  int ans;
  int sum;
  int min;
  scanf("%d", &T);
  for (i = 0; i < T; i++)
  {
    printf("Case #%d: ", i + 1);
    scanf("%d", &N);
    sum = 0;
    min = 1000000;
    for (j = 0; j < N; j++)
    {
      scanf("%d", &C[j]);
      if (C[j] < min)
        min = C[j];

      sum += C[j];
    }

    ans = xor_array(N);
    if (ans != 0)
      printf("NO\n");
    else
      printf("%d\n", sum - min);

  }

  return 0;
}


