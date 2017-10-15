#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int depth[128][128];
char mrc[128][128];
int m;
int c2;
int Main(void)
{
  int first_iteration;
  int nc;
  int numToEbits;
  int i;
  int j;
  int start;
  for (scanf("%d", &nc), numToEbits = 1; numToEbits <= nc; numToEbits++)
  {
    scanf("%d%d", &m, &c2);
    memset(mrc, 0, sizeof(mrc));
    for (scanf("%d", &start); start > 0; start--)
    {
      scanf("%d%d", &i, &j);
      mrc[i][j] = 1;
    }

    memset(depth, 0, sizeof(depth));
    depth[1][1] = 1;
    for (i = 2; i <= m; i++)
    {
      for (j = 2; j <= c2; j++)
      {
        if (mrc[i][j])
          continue;

        depth[i][j] = (depth[i][j] + depth[i - 2][j - 1]) % 10007;
        depth[i][j] = (depth[i][j] + depth[i - 1][j - 2]) % 10007;
      }

    }

    printf("Case #%d:", numToEbits);
    printf(" %d\n", depth[m][c2]);
  }

  return 0;
}


