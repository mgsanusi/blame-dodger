#include<stdio.h>
int T;
int t;
int N;
int A[2048];
int B[2048];
int X[2048];
int done;
int i;
int j;
void foo(int i);
int main()
{
  int first_iteration;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d", &N);
    done = 0;
    for (i = 0; i < N; i++)
    {
      A[i] = (B[i] = (X[i] = 0));
    }

    for (i = 0; i < N; i++)
    {
      scanf("%d", &A[i]);
    }

    for (i = 0; i < N; i++)
    {
      scanf("%d", &B[i]);
    }

    for (i = 0; i < N; i++)
    {
      X[0] = i;
      done = 0;
      foo(1);
      if (done)
        break;

    }

    printf("Case #%d: ", t);
    for (i = 0; i < (N - 1); i++)
    {
      printf("%d ", X[i] + 1);
    }

    printf("%d\n", X[N - 1] + 1);
  }

  return 0;
}

void foo(int i)
{
  int first_iteration;
  int best_a;
  int j;
  int k;
  int best_b;
  if (i == N)
  {
    for (j = N - 1; j >= 0; j--)
    {
      best_b = 1;
      for (k = j + 1; k < N; k++)
      {
        if ((X[j] > X[k]) && (best_b <= B[k]))
          best_b = B[k] + 1;

      }

      if (best_b != B[j])
        return;

    }

    done = 1;
    return;
  }

  for (X[i] = 0; X[i] < N; X[i]++)
  {
    best_a = 1;
    for (j = 0; j < i; j++)
    {
      if ((X[j] < X[i]) && (A[j] >= best_a))
        best_a = A[j] + 1;
      else
        if (X[i] == X[j])
        break;


    }

    if (i != j)
      continue;

    if (A[i] == best_a)
    {
      foo(i + 1);
      if (done)
        return;

    }

  }

}


