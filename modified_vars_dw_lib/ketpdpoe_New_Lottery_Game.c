#include<stdio.h>
#include<string.h>
int Main()
{
  int first_iteration;
  int t;
  int i;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    char e[100][105];
    int move[105][105] = {};
    int n2;
    int j;
    int x;
    scanf("%d", &x);
    int c;
    for (n2 = 0; n2 < x; n2++)
    {
      scanf("%s", e[n2]);
      int f = strlen(e[n2]);
      c = 1;
      for (j = 1; j < f; j++)
      {
        if (e[n2][j] == e[n2][j - 1])
        {
          move[n2][c - 1]++;
        }
        else
        {
          e[n2][c] = e[n2][j];
          c++;
        }

      }

      e[n2][c] = '\0';
    }

    int z = 1;
    int tmp;
    int k;
    printf("Case #%d: ", i + 1);
    for (n2 = 1; n2 < x; n2++)
      if (strcmp(e[n2], e[0]) != 0)
    {
      z = 0;
      break;
    }


    if (z == 0)
      printf("Fegla Won\n");
    else
    {
      int result = 0;
      int mid;
      for (k = 0; k < c; k++)
      {
        for (n2 = 0; n2 < x; n2++)
        {
          for (j = n2 + 1; j < x; j++)
          {
            if (move[n2][k] > move[j][k])
            {
              tmp = move[n2][k];
              move[n2][k] = move[j][k];
              move[j][k] = tmp;
            }

          }

        }

        if ((x % 2) == 0)
        {
          mid = (move[x / 2][k] + move[(x / 2) - 1][k]) / 2;
        }
        else
          mid = move[x / 2][k];

        for (n2 = 0; n2 < x; n2++)
        {
          if (mid > move[n2][k])
            result += mid - move[n2][k];
          else
            result += move[n2][k] - mid;

        }

      }

      printf("%d\n", result);
    }

  }

  return 0;
}


