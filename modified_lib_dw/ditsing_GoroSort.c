#include <stdio.h>
#include <string.h>
char graph[100][100];
char input[100 << 1];
int N;
double wp[100];
double owp[100];
double oowp[100];
int main()
{
  int first_iteration;
  int Tcases;
  scanf("%d", &Tcases);
  int cases;
  for (cases = 0; cases < Tcases; cases++)
  {
    scanf("%d ", &N);
    int i;
    int j;
    int k;
    for (i = 0; i < N; i++)
    {
      scanf("%s", input);
      for (j = 0; j < N; j++)
      {
        graph[i][j] = input[j];
      }

    }

    for (i = 0; i < N; i++)
    {
      wp[i] = 0.0;
      int cnt = 0;
      for (j = 0; j < N; j++)
      {
        if (graph[i][j] != '.')
        {
          ++cnt;
          wp[i] += graph[i][j] == '1';
        }

      }

      wp[i] /= cnt;
    }

    for (i = 0; i < N; i++)
    {
      owp[i] = 0.0;
      int cnt = 0;
      for (j = 0; j < N; j++)
      {
        if (graph[i][j] != '.')
        {
          double wpj = 0.0;
          int cntj = 0;
          for (k = 0; k < N; k++)
          {
            if ((graph[j][k] != '.') && (k != i))
            {
              wpj += graph[j][k] == '1';
              ++cntj;
            }

          }

          ++cnt;
          owp[i] += wpj / cntj;
        }

      }

      owp[i] /= cnt;
    }

    for (i = 0; i < N; i++)
    {
      oowp[i] = 0.0;
      int cnt = 0;
      for (j = 0; j < N; j++)
      {
        if (graph[i][j] != '.')
        {
          ++cnt;
          oowp[i] += owp[j];
        }

      }

      oowp[i] /= cnt;
    }

    printf("Case #%d:\n", cases + 1);
    for (i = 0; i < N; i++)
    {
      printf("%.10lf\n", ((0.25 * wp[i]) + (0.5 * owp[i])) + (0.25 * oowp[i]));
    }

  }

  return 0;
}


