#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
double V;
double X;
double R[100];
double C[100];
double second;
void solve(void)
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < N; ++i)
  {
    if (C[i] <= X)
      break;

  }

  for (j = 0; j < N; ++j)
  {
    if (C[j] >= X)
      break;

  }

  if ((i == N) || (j == N))
  {
    second = -1.0f;
    return;
  }

  if ((C[0] == X) && (C[1] != X))
  {
    second = V / R[0];
  }
  else
    if ((C[0] != X) && (C[1] == X))
  {
    second = V / R[1];
  }
  else
    if ((C[0] == X) && (C[1] == X))
  {
    second = V / (R[0] + R[1]);
  }
  else
  {
    double V1 = ((C[0] - X) * V) / (C[0] - C[1]);
    double V0 = V - V1;
    double t0 = V0 / R[0];
    double t1 = V1 / R[1];
    if (t0 < t1)
      second = t1;
    else
      second = t0;

  }



}

void solve_and_print(void)
{
  int first_iteration;
  int i;
  scanf("%d %lf %lf", &N, &V, &X);
  for (i = 0; i < N; ++i)
  {
    scanf("%lf %lf", R + i, C + i);
  }

  second = 0.0f;
  solve();
  if (second < 0.0)
  {
    printf("IMPOSSIBLE\n");
  }
  else
  {
    printf("%.9lf\n", second);
  }

}

int main(void)
{
  int first_iteration;
  int dataset_num;
  int case_num;
  scanf("%d", &dataset_num);
  for (case_num = 1; case_num <= dataset_num; ++case_num)
  {
    printf("Case #%d: ", case_num);
    solve_and_print();
  }

  return 0;
}


