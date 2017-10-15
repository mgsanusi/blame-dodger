#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
int graph[1024][1024] = {{0}};
int label[1024] = {0};
void *new_memset(void *ptr, int value, size_t num);
int dfs(int start, int N)
{
  int first_iteration;
  for (int i = 1; i <= N; i++)
  {
    if (graph[start][i] != 0)
    {
      if (label[i] == 0)
      {
        label[i] = 1;
        int x = dfs(i, N);
        if (x == 1)
          return 1;

      }
      else
      {
        return 1;
      }

    }

  }

  return 0;
}

int main()
{
  int first_iteration;
  int T = 0;
  int N = 0;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++)
  {
    new_memset(graph, 0, sizeof(graph));
    new_memset(label, 0, sizeof(label));
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
      int x = 0;
      int k = 0;
      scanf("%d", &x);
      for (int j = 0; j < x; j++)
      {
        scanf("%d", &k);
        graph[i][k] = 1;
      }

    }

    int res = 0;
    for (int i = 1; i <= N; i++)
    {
      if (label[i] == 0)
      {
        label[i] = 1;
        new_memset(label, 0, sizeof(label));
        int x = dfs(i, N);
        if (x == 1)
        {
          res = 1;
          break;
        }

      }

    }

    printf("Case #%d: ", cas);
    if (res)
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }

  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


