#include<stdio.h>
#include<string.h>
void foo(int a, int cost);
int c;
int t;
int T;
int m;
int n;
int M;
int N;
char S[1024][128];
int pref[1024][1024];
int foob[1024];
int fooc[128];
int max;
int number;
int main()
{
  int first_iteration;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d", &M);
    scanf("%d", &N);
    for (m = 1; m <= M; m++)
    {
      scanf("%s", &S[m][0]);
      pref[0][m] = strlen(&S[m][0]);
    }

    for (m = 1; m <= M; m++)
    {
      for (n = 1; n < m; n++)
      {
        for (c = 0; S[m][c] == S[n][c]; c++)
        {
        }

        pref[m][n] = pref[0][n] - c;
        pref[n][m] = pref[0][m] - c;
      }

    }

    max = 0;
    number = 0;
    foo(1, 0);
    printf("Case #%d: %d %d\n", t, max + N, number);
  }

  return 0;
}

void foo(int a, int cost)
{
  int first_iteration;
  int p;
  int min_cost;
  if (a <= M)
  {
    for (foob[a] = 0; foob[a] < N; foob[a]++)
    {
      fooc[foob[a]]++;
      min_cost = pref[0][a];
      for (p = 1; p < a; p++)
      {
        if (foob[p] == foob[a])
          if (min_cost > pref[p][a])
        {
          min_cost = pref[p][a];
        }


      }

      foo(a + 1, cost + min_cost);
      fooc[foob[a]]--;
    }

  }
  else
  {
    for (p = 0; p < N; p++)
    {
      if (fooc[p] == 0)
        return;

    }

    if (cost > max)
    {
      max = cost;
      number = 0;
    }

    if (cost == max)
    {
      number++;
    }

  }

}


