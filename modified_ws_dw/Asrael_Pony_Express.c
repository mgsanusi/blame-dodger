#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int tot;
int N;
int Q;
int E[100];
double S[100];
int D[100][100];
int U[100];
int V[100];
double T[100][100];
double recurse(int start, int des)
{
  int first_iteration;
  double A[100];
  if (start == des)
    return 0;

  int j = 1;
  A[0] = (D[start][start + 1] / S[start]) + recurse(start + 1, des);
  int left = E[start] - D[start][start + 1];
  while (((j + start) < des) && (left >= D[start + j][(start + j) + 1]))
  {
    A[j] = 0;
    for (int k = 0; k <= j; k++)
      A[j] += D[start + k][(start + k) + 1] / S[start];

    A[j] += recurse((start + 1) + j, des);
    if (A[j] > A[j - 1])
      A[j] = A[j - 1];

    left -= D[start + j][(start + j) + 1];
    j++;
  }

  return A[j - 1];
}

int main()
{
  int first_iteration;
  scanf("%d", &tot);
  for (int i = 1; i <= tot; i++)
  {
    scanf("%d%d", &N, &Q);
    for (int j = 0; j < N; j++)
      scanf("%d%lf", &E[j], &S[j]);

    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
      scanf("%d", &D[j][k]);


    for (int j = 0; j < Q; j++)
      scanf("%d%d", &U[j], &V[j]);

    printf("Case #%d: %lf\n", i, recurse(U[0] - 1, V[0] - 1));
  }

  return 0;
}


