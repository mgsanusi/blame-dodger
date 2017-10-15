#include <stdio.h>
int protable[8][8] = {{0, 1, 2, 3, 4, 5, 6, 7}, {1, 4, 3, 6, 5, 0, 7, 2}, {2, 7, 4, 1, 6, 3, 0, 5}, {3, 2, 5, 4, 7, 6, 1, 0}, {4, 5, 6, 7, 0, 1, 2, 3}, {5, 0, 7, 2, 1, 4, 3, 6}, {6, 3, 0, 5, 2, 7, 4, 1}, {7, 6, 1, 0, 3, 2, 5, 4}};
int main()
{
  int first_iteration;
  int T;
  int t;
  int X;
  int L;
  char s[10001];
  int left;
  int right;
  int a;
  int leftpos[2];
  int rightpos[2];
  int i;
  int j;
  int m;
  int n;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d %d\n", &L, &X);
    scanf("%s\n", s);
    left = (right = 0);
    m = 0;
    for (j = 0; j < L; j++)
      m = protable[m][(s[j] - 'i') + 1];

    n = 0;
    for (i = 0; i < (X % 4); i++)
      n = protable[n][m];

    if (n != 4)
    {
      printf("Case #%d: NO\n", t);
      continue;
    }

    m = 0;
    for (i = 0; i < 4; i++)
    {
      for (j = 0; j < L; j++)
      {
        m = protable[m][(s[j] - 'i') + 1];
        if ((m == 1) && (!left))
        {
          left = 1;
          leftpos[0] = i;
          leftpos[1] = j;
          break;
        }

      }

      if (left)
        break;

    }

    m = 0;
    for (i = 0; i < 4; i++)
    {
      for (j = L - 1; j >= 0; j--)
      {
        m = protable[(s[j] - 'i') + 1][m];
        if ((m == 3) && (!right))
        {
          right = 1;
          rightpos[0] = i;
          rightpos[1] = j;
          break;
        }

      }

      if (right)
        break;

    }

    if (left && right)
    {
      if (leftpos[0] < ((X - rightpos[0]) - 1))
      {
        printf("Case #%d: YES\n", t);
      }
      else
        if ((leftpos[0] == ((X - rightpos[0]) - 1)) && (leftpos[1] < rightpos[1]))
      {
        printf("Case #%d: YES\n", t);
      }
      else
      {
        printf("Case #%d: NO\n", t);
      }


    }
    else
    {
      printf("Case #%d: NO\n", t);
    }

  }

  return 0;
}


