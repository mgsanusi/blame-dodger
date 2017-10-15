#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
typedef unsigned long long ubig;
typedef long long big;
int compar(void *data, const void *one, const void *two)
{
  int first_iteration;
  int *ione = *((int **) one);
  int *itwo = *((int **) two);
  int N = *((int *) data);
  int i;
  for (i = 0; i < N; i++)
  {
    if (ione[i] < itwo[i])
    {
      return -1;
    }
    else
      if (ione[i] > itwo[i])
    {
      return 1;
    }


  }

  return 0;
}

int main()
{
  int first_iteration;
  long num;
  long iii;
  scanf(" %ld", &num);
  for (iii = 0; iii < num; iii++)
  {
    ubig N;
    scanf(" %llu", &N);
    int **input = malloc((sizeof(int *)) * ((2 * N) - 1));
    if (!input)
    {
      return 1;
    }

    int i;
    for (i = 0; i < ((2 * N) - 1); i++)
    {
      input[i] = malloc((sizeof(int)) * N);
      if (!input[i])
      {
        return 1;
      }

      int j;
      for (j = 0; j < N; j++)
      {
        scanf(" %d", &input[i][j]);
      }

    }

    qsort_r(input, (2 * N) - 1, sizeof(int *), &N, compar);
    int *totals = malloc((sizeof(int)) * 2500);
    memset(totals, 0, (sizeof(int)) * 2500);
    for (i = 0; i < ((2 * N) - 1); i++)
    {
      int j;
      for (j = 0; j < N; j++)
      {
        totals[input[i][j] - 1]++;
      }

    }

    printf("Case #%ld: ", iii + 1);
    for (i = 0; i < 2500; i++)
    {
      if ((totals[i] % 2) == 1)
      {
        printf("%d ", i + 1);
      }

    }

    printf("\n");
    free(totals);
    for (i = 0; i < N; i++)
    {
      free(input[i]);
    }

    free(input);
  }

  return 0;
}


