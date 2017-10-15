#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int data[100][100];
int N;
int M;
int check(int x, int y)
{
  int first_iteration;
  int i;
  int j;
  int t = data[x][y];
  int result = 1;
  for (i = 0; i < N; ++i)
  {
    if (t < data[i][y])
    {
      result = 0;
      break;
    }

  }

  if (result)
    return 1;

  for (i = 0; i < M; ++i)
  {
    if (t < data[x][i])
    {
      return 0;
    }

  }

  return 1;
}

int main(void)
{
  int first_iteration;
  int num;
  int i;
  int j;
  int k;
  int result;
  scanf("%d", &num);
  for (i = 1; i <= num; ++i)
  {
    scanf("%d %d", &N, &M);
    for (j = 0; j < N; ++j)
    {
      for (k = 0; k < M; ++k)
      {
        scanf("%d", &data[j][k]);
      }

    }

    result = 1;
    for (j = 0; j < N; ++j)
    {
      for (k = 0; k < M; ++k)
      {
        if (!check(j, k))
        {
          result = 0;
          goto LAST;
        }

      }

    }

    LAST:
    printf("Case #%d: ", i);

    if (result)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }

  }

  return 0;
}


