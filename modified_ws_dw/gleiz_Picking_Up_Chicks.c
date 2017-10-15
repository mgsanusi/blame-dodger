#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
int A[1024];
int B[1024];
int main(int argc, char *argv[])
{
  int first_iteration;
  int i = 0;
  int j = 0;
  int k = 0;
  int T = 0;
  int N = 0;
  int cas = 1;
  int res = 0;
  int high[2];
  int low[2];
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
      scanf("%d %d", &A[i], &B[i]);
    }

    res = 0;
    for (i = 0; i < N; i++)
    {
      for (j = i + 1; j < N; j++)
      {
        if (A[i] > A[j])
        {
          high[0] = A[i];
          high[1] = B[i];
          low[0] = A[j];
          low[1] = B[j];
        }
        else
        {
          high[0] = A[j];
          high[1] = B[j];
          low[0] = A[i];
          low[1] = B[i];
        }

        if (high[1] <= low[1])
        {
          res++;
        }

      }

    }

    printf("Case #%d: %d\n", cas++, res);
  }

  return 0;
}


