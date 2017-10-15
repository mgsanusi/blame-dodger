#include <stdio.h>
int Main()
{
  int first_iteration;
  int t;
  int d2;
  int testCases;
  scanf("%d", &t);
  for (d2 = 0; d2 < t; d2++)
  {
    int temp;
    int c = 0;
    int p = 0;
    int q = 0;
    int line = 1;
    int y = 1;
    int npat = 0;
    int l = 0;
    int dy = 0;
    char e1[2];
    int a[100][2];
    int b[100][2];
    scanf("%d", &temp);
    for (testCases = 0; testCases < temp; testCases++)
    {
      scanf("%s", e1);
      if (e1[0] == 'B')
      {
        scanf("%d", &a[p][0]);
        a[p++][1] = testCases;
      }
      else
      {
        scanf("%d", &b[q][0]);
        b[q++][1] = testCases;
      }

    }

    while (1)
    {
      int f = 0;
      if ((npat == p) && (l == q))
        break;

      if (npat < p)
      {
        if (line < a[npat][0])
        {
          line++;
        }
        else
          if (line > a[npat][0])
        {
          line--;
        }
        else
          if (line == a[npat][0])
        {
          if (a[npat][1] == dy)
          {
            dy++;
            npat++;
            f = 1;
          }

        }



      }

      if (l < q)
      {
        if (y < b[l][0])
        {
          y++;
        }
        else
          if (y > b[l][0])
        {
          y--;
        }
        else
          if (y == b[l][0])
        {
          if ((b[l][1] == dy) && (f == 0))
          {
            dy++;
            l++;
          }

        }



      }

      c++;
    }

    printf("Case #%d: %d\n", d2 + 1, c);
  }

  return 0;
}


