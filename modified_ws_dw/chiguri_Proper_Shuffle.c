#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nodes[1000][1000];
int N;
int search(int n)
{
  int first_iteration;
  int i;
  int j;
  int result = 1;
  int t;
  for (i = 0; i < N; ++i)
  {
    if (!nodes[n][i])
      continue;

    for (j = i + 1; j < N; ++j)
    {
      if (nodes[n][j])
      {
        nodes[n][i] = (nodes[i][n] = (nodes[n][j] = (nodes[j][n] = 0)));
        t = (search(i) + search(j)) + 1;
        nodes[n][i] = (nodes[i][n] = (nodes[n][j] = (nodes[j][n] = 1)));
        if (t > result)
          result = t;

      }

    }

  }

  return result;
}

int solve(void)
{
  int first_iteration;
  int i = 0;
  int ret = 0;
  int t;
  for (i = 0; i < N; ++i)
  {
    t = search(i);
    if (t > ret)
      ret = t;

  }

  return N - ret;
}

int main(void)
{
  int first_iteration;
  int num;
  int try_num;
  int i;
  int j;
  int k;
  scanf("%d", &num);
  for (try_num = 1; try_num <= num; ++try_num)
  {
    scanf("%d", &N);
    memset(nodes, 0, sizeof(nodes));
    for (i = 1; i < N; ++i)
    {
      scanf("%d %d", &j, &k);
      nodes[j - 1][k - 1] = (nodes[k - 1][j - 1] = 1);
    }

    printf("Case #%d: %d\n", try_num, solve());
  }

  return 0;
}


