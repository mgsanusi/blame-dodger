#include <stdio.h>
#include <string.h>
int swapchair[10001][2];
int node[10001][2];
int c;
int j;
int min(int a, int p)
{
  int first_iteration;
  return a > p ? p : a;
}

void go()
{
  int first_iteration;
  int res;
  int a;
  int p;
  int total;
  int str;
  scanf("%d%d", &c, &j);
  memset(swapchair, 0, sizeof(swapchair));
  memset(node, 0, sizeof(node));
  for (res = 1; res <= ((c - 1) / 2); res++)
  {
    scanf("%d%d", &node[res][0], &node[res][1]);
  }

  for (res = ((c - 1) / 2) + 1; res <= c; res++)
  {
    scanf("%d", &str);
    if (str == 0)
    {
      swapchair[res][0] = 0;
      swapchair[res][1] = 99999999;
    }

    if (str == 1)
    {
      swapchair[res][1] = 0;
      swapchair[res][0] = 99999999;
    }

  }

  for (res = (c - 1) / 2; res > 0; res--)
  {
    swapchair[res][0] = 99999999;
    swapchair[res][1] = 99999999;
    for (a = 0; a < 2; a++)
      for (p = 0; p < 2; p++)
      if ((swapchair[res * 2][a] != 99999999) && (swapchair[(res * 2) + 1][p] != 99999999))
    {
      total = swapchair[res * 2][a] + swapchair[(res * 2) + 1][p];
      if (node[res][0] == 1)
      {
        swapchair[res][a && p] = min(swapchair[res][a && p], total);
      }
      else
      {
        swapchair[res][a || p] = min(swapchair[res][a || p], total);
      }

      if (node[res][1] == 1)
      {
        if (node[res][0] == 0)
        {
          swapchair[res][a && p] = min(swapchair[res][a && p], total + 1);
        }
        else
        {
          swapchair[res][a || p] = min(swapchair[res][a || p], total + 1);
        }

      }

    }



  }

}

int Main()
{
  int first_iteration;
  int m2;
  int res;
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  scanf("%d", &m2);
  for (res = 0; res < m2; res++)
  {
    go();
    printf("Case #%d: ", res + 1);
    if (swapchair[1][j] == 99999999)
    {
      printf("IMPOSSIBLE\n");
    }
    else
    {
      printf("%d\n", swapchair[1][j]);
    }

  }

  return 0;
}


