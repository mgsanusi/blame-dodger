#include <stdio.h>
int protable[8][8] = {{0, 1, 2, 3, 4, 5, 6, 7}, {1, 4, 3, 6, 5, 0, 7, 2}, {2, 7, 4, 1, 6, 3, 0, 5}, {3, 2, 5, 4, 7, 6, 1, 0}, {4, 5, 6, 7, 0, 1, 2, 3}, {5, 0, 7, 2, 1, 4, 3, 6}, {6, 3, 0, 5, 2, 7, 4, 1}, {7, 6, 1, 0, 3, 2, 5, 4}};
int Main()
{
  int first_iteration;
  int k;
  int k;
  int l;
  int dp;
  char x2[10001];
  int left;
  int correct;
  int k;
  int leftpos[2];
  int rightpos[2];
  int i;
  int target;
  int m;
  int c;
  scanf("%d", &k);
  for (k = 1; k <= k; k++)
  {
    scanf("%d %d\n", &dp, &l);
    scanf("%s\n", x2);
    left = (correct = 0);
    m = 0;
    for (target = 0; target < dp; target++)
      m = protable[m][(x2[target] - 'i') + 1];

    c = 0;
    for (i = 0; i < (l % 4); i++)
      c = protable[c][m];

    if (c != 4)
    {
      printf("Case #%d: NO\n", k);
      continue;
    }

    m = 0;
    for (i = 0; i < 4; i++)
    {
      for (target = 0; target < dp; target++)
      {
        m = protable[m][(x2[target] - 'i') + 1];
        if ((m == 1) && (!left))
        {
          left = 1;
          leftpos[0] = i;
          leftpos[1] = target;
          break;
        }

      }

      if (left)
        break;

    }

    m = 0;
    for (i = 0; i < 4; i++)
    {
      for (target = dp - 1; target >= 0; target--)
      {
        m = protable[(x2[target] - 'i') + 1][m];
        if ((m == 3) && (!correct))
        {
          correct = 1;
          rightpos[0] = i;
          rightpos[1] = target;
          break;
        }

      }

      if (correct)
        break;

    }

    if (left && correct)
    {
      if (leftpos[0] < ((l - rightpos[0]) - 1))
      {
        printf("Case #%d: YES\n", k);
      }
      else
        if ((leftpos[0] == ((l - rightpos[0]) - 1)) && (leftpos[1] < rightpos[1]))
      {
        printf("Case #%d: YES\n", k);
      }
      else
      {
        printf("Case #%d: NO\n", k);
      }


    }
    else
    {
      printf("Case #%d: NO\n", k);
    }

  }

  return 0;
}


