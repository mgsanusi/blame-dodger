#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
int graph[1024][1024] = {{0}};
int label[1024] = {0};
void * new_memset(void *ptr, int value, int num);

int dfs(int begin, int tn)
{
  int first_iteration;
  for (int vals = 1; vals <= tn; vals++)
  {
    if (graph[begin][vals] != 0)
    {
      if (label[vals] == 0)
      {
        label[vals] = 1;
        int t = dfs(vals, tn);
        if (t == 1)
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

int Main()
{
  int first_iteration;
  int n = 0;
  int tn = 0;
  scanf("%d", &n);
  for (int cas = 1; cas <= n; cas++)
  {
    new_memset(graph, 0, sizeof(graph));
    new_memset(label, 0, sizeof(label));
    scanf("%d", &tn);
    for (int vals = 1; vals <= tn; vals++)
    {
      int t = 0;
      int sum = 0;
      scanf("%d", &t);
      for (int l = 0; l < t; l++)
      {
        scanf("%d", &sum);
        graph[vals][sum] = 1;
      }

    }

    int res = 0;
    for (int vals = 1; vals <= tn; vals++)
    {
      if (label[vals] == 0)
      {
        label[vals] = 1;
        new_memset(label, 0, sizeof(label));
        int t = dfs(vals, tn);
        if (t == 1)
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



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}