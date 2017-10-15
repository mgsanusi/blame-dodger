#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int scores[222];
int state[222];
int total;
int flag;
double chance;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int main()
{
  int first_iteration;
  new_freopen("A-small-attempt2.in", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  int cases;
  int case_index;
  int i;
  int j;
  int n;
  double x;
  double sum;
  double sum2;
  scanf("%d", &cases);
  for (case_index = 1; case_index <= cases; case_index++)
  {
    scanf("%d", &n);
    x = 0;
    for (i = 0; i < n; i++)
    {
      scanf("%d", &scores[i]);
      x += scores[i];
    }

    printf("Case #%d:", case_index);
    for (i = 0; i < n; i++)
    {
      total = 0;
      sum2 = 0;
      memset(state, 0, sizeof(state));
      again:
      chance = (100 * ((((2 * x) - sum2) / (n - total)) - scores[i])) / x;

      sum = scores[i] + ((x * chance) / 100);
      flag = 0;
      if (chance > 0.000001)
        for (j = 0; j < n; j++)
      {
        if ((sum < scores[j]) && (state[j] == 0))
        {
          state[j] = 1;
          total++;
          flag = 1;
          sum2 += scores[j];
        }

      }


      if (flag == 1)
        goto again;

      if (chance >= 0.0)
        printf(" %f", chance);
      else
        printf(" %f", 0.0);

    }

    printf("\n");
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


