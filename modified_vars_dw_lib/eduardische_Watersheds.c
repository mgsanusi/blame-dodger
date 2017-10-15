#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int h;
int barber;
char dfs(int xdrs[105][105], char n[105][105], int p, int start, char next)
{
  int first_iteration;
  if (n[p][start] != 0)
    return n[p][start];

  int min = xdrs[p][start];
  int minx = -1;
  int miny = -1;
  if ((p > 0) && (xdrs[p - 1][start] < min))
  {
    min = xdrs[p - 1][start];
    minx = p - 1;
    miny = start;
  }

  if ((start > 0) && (xdrs[p][start - 1] < min))
  {
    min = xdrs[p][start - 1];
    minx = p;
    miny = start - 1;
  }

  if ((start < (barber - 1)) && (xdrs[p][start + 1] < min))
  {
    min = xdrs[p][start + 1];
    minx = p;
    miny = start + 1;
  }

  if ((p < (h - 1)) && (xdrs[p + 1][start] < min))
  {
    min = xdrs[p + 1][start];
    minx = p + 1;
    miny = start;
  }

  if (minx == (-1))
    n[p][start] = next;
  else
    n[p][start] = dfs(xdrs, n, minx, miny, next);

  return n[p][start];
}

int Main()
{
  int first_iteration;
  static int xdrs[105][105];
  static char n[105][105];
  int t;
  scanf("%d", &t);
  int tid;
  int caseId;
  int n;
  char next;
  for (n = 0; n < t; n++)
  {
    scanf("%d %d", &h, &barber);
    for (tid = 0; tid < h; tid++)
    {
      for (caseId = 0; caseId < barber; caseId++)
      {
        scanf("%d", &xdrs[tid][caseId]);
      }

    }

    memset(n, 0, sizeof(n));
    next = 'a';
    for (tid = 0; tid < h; tid++)
    {
      for (caseId = 0; caseId < barber; caseId++)
      {
        if (n[tid][caseId] == 0)
        {
          if (dfs(xdrs, n, tid, caseId, next) == next)
            next++;

        }

      }

    }

    printf("Case #%d:\n", n + 1);
    for (tid = 0; tid < h; tid++)
    {
      for (caseId = 0; caseId < barber; caseId++)
      {
        if (caseId > 0)
          printf(" ");

        printf("%c", n[tid][caseId]);
      }

      printf("\n");
    }

  }

  return 0;
}


