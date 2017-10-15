#include <stdio.h>
#include <string.h>
int iStart[105][105];
int tmp;
int c;
char rslt[105][105];
char visit[105][105];
char now;
char dfs(int i, int f)
{
  int first_iteration;
  int ii = -1;
  int leftFree = -1;
  int caseno = iStart[i][f];
  if (visit[i][f])
    return rslt[i][f];

  visit[i][f] = 1;
  if ((i > 0) && (iStart[i - 1][f] < caseno))
    ii = -1, leftFree = 0, caseno = iStart[i - 1][f];

  if ((f > 0) && (iStart[i][f - 1] < caseno))
    ii = 0, leftFree = -1, caseno = iStart[i][f - 1];

  if ((f < (c - 1)) && (iStart[i][f + 1] < caseno))
    ii = 0, leftFree = 1, caseno = iStart[i][f + 1];

  if ((i < (tmp - 1)) && (iStart[i + 1][f] < caseno))
    ii = 1, leftFree = 0, caseno = iStart[i + 1][f];

  return rslt[i][f] = (ii == (-1)) && (leftFree == (-1)) ? now++ : dfs(i + ii, f + leftFree);
}

int Main()
{
  int first_iteration;
  int g;
  int caso = 1;
  int i;
  int f;
  scanf("%d", &g);
  while (g--)
  {
    scanf("%d %d", &tmp, &c);
    for (i = 0; i < tmp; i++)
    {
      for (f = 0; f < c; f++)
      {
        scanf("%d", &iStart[i][f]);
      }

    }

    now = 'a';
    memset(visit, 0, sizeof(visit));
    for (i = 0; i < tmp; i++)
    {
      for (f = 0; f < c; f++)
      {
        if (!visit[i][f])
        {
          dfs(i, f);
        }

      }

    }

    printf("Case #%d:\n", caso++);
    for (i = 0; i < tmp; i++)
    {
      printf("%c", rslt[i][0]);
      for (f = 1; f < c; f++)
      {
        printf(" %c", rslt[i][f]);
      }

      puts("");
    }

  }

  return 0;
}


