#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int TC;
int T;
int Numbers;
double N[2][1200];
int i;
int x;
int y;
int Ans;
int L;
int R;
int QS(double *A, double *B)
{
  int first_iteration;
  if ((*A) > (*B))
    return -1;

  if ((*A) < (*B))
    return 1;

  return 0;
}

int Ans1()
{
  int first_iteration;
  Ans = 0;
  R = Numbers - 1;
  for (x = Numbers - 1; x >= 0; x--)
  {
    if (N[0][x] >= N[1][R])
    {
      R--;
      Ans++;
    }

  }

  return Ans;
}

int Ans2()
{
  int first_iteration;
  R = Numbers - 1;
  for (x = Numbers - 1; x >= 0; x--)
  {
    while (N[0][x] > N[1][R])
    {
      R--;
      if (R < 0)
        break;

    }

    if (R < 0)
      break;

    R--;
  }

  return x + 1;
}

int main()
{
  int first_iteration;
  freopen("D-small-attempt0.in", "r", stdin);
  freopen("D-small-attempt0.out", "w", stdout);
  scanf("%d", &TC);
  for (T = 1; T <= TC; T++)
  {
    printf("Case #%d: ", T);
    scanf("%d", &Numbers);
    for (i = 0; i < 2; i++)
    {
      for (x = 0; x < Numbers; x++)
        scanf("%lf", &N[i][x]);

      qsort(N[i], Numbers, sizeof(N[0][0]), QS);
    }

    printf("%d %d\n", Ans1(), Ans2());
  }

  return 0;
}


