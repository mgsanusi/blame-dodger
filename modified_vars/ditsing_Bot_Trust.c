#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int dp[100][100];
int n[100];
int len[100];
int pos[2][100];
int j;
int Main()
{
  int tcases;
  scanf("%d", &tcases);
  int subject;
  for (subject = 0; subject != tcases; subject++)
  {
    memset(dp, 0x3F, sizeof(dp));
    scanf("%d", &j);
    char jj;
    int dis;
    int input;
    for (input = 0; input < j; input++)
    {
      scanf(" %c %d", &jj, &dis);
      --dis;
      len[input] = jj != 'O';
      n[input] = dis;
      pos[len[input]][input] = dis;
      pos[1 - len[input]][input] = -1;
    }

    for (input = j - 1; input; input--)
    {
      if (pos[0][input - 1] == (-1))
      {
        pos[0][input - 1] = pos[0][input];
      }

      if (pos[1][input - 1] == (-1))
      {
        pos[1][input - 1] = pos[1][input];
      }

    }

    int rslt = 0;
    int cur[2] = {0, 0};
    for (input = 0; input < j; input++)
    {
      int curl = abs(cur[len[input]] - n[input]) + 1;
      cur[len[input]] = n[input];
      rslt += curl;
      if (pos[1 - len[input]][input] != (-1))
      {
        if (abs(cur[1 - len[input]] - pos[1 - len[input]][input]) <= curl)
        {
          cur[1 - len[input]] = pos[1 - len[input]][input];
        }
        else
        {
          if (pos[1 - len[input]][input] > cur[1 - len[input]])
          {
            cur[1 - len[input]] += curl;
          }
          else
          {
            cur[1 - len[input]] -= curl;
          }

        }

      }

    }

    printf("Case #%d: %d\n", subject + 1, rslt);
  }

  return 0;
}


