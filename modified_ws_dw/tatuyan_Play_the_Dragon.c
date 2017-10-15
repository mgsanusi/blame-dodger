#include<stdio.h>
void solve(int cases);
int main(void)
{
  int first_iteration;
  int T;
  int i;
  scanf("%d", &T);
  for (i = 1; i <= T; i++)
    solve(i);

  return 0;
}

void solve(int cases)
{
  int first_iteration;
  long long N;
  long long Q;
  long long E[100];
  long long S[100];
  long long D[100][100];
  long long dist[100];
  long long U[100];
  long long V[100];
  int i;
  int j;
  int k;
  double times[100][100];
  double anstime[100] = {0};
  double tmp;
  scanf("%lld%lld", &N, &Q);
  for (i = 0; i < N; i++)
    scanf("%lld%lld", &E[i], &S[i]);

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
    scanf("%lld", &D[i][j]);


  for (i = 0; i < Q; i++)
    scanf("%lld%lld", &U[i], &V[i]);

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
    times[i][j] = -1;


  for (dist[0] = 0, i = 1; i < N; i++)
    dist[i] = D[i - 1][i] + dist[i - 1];

  for (i = 0; i < N; i++)
  {
    if (i == 0)
      anstime[i] = 0;
    else
    {
      tmp = times[0][i];
      for (j = 1; j < i; j++)
      {
        if (times[j][i] < 0)
          continue;

        if ((tmp < 0) || (tmp > times[j][i]))
          tmp = times[j][i];

      }

      anstime[i] = tmp;
    }

    for (j = i + 1; (j < N) && (E[i] >= (dist[j] - dist[i])); j++)
    {
      times[i][j] = anstime[i] + (((double) (dist[j] - dist[i])) / ((double) S[i]));
    }

  }

  printf("Case #%d: %.8lf\n", cases, anstime[N - 1]);
}


