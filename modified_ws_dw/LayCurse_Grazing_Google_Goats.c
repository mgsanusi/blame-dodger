#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int now[200][200];
int next[200][200];
int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int res;
  int x1;
  int y1;
  int x2;
  int y2;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &n);
    for (i = 0; i < 200; i++)
      for (j = 0; j < 200; j++)
      now[i][j] = 0;


    for (k = 0; k < n; k++)
    {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      for (i = x1; i < (x2 + 1); i++)
        for (j = y1; j < (y2 + 1); j++)
        now[i][j] = 1;


    }

    n = 1;
    res = 0;
    while (n)
    {
      res++;
      n = 0;
      for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
        next[i][j] = 0;


      for (i = 1; i < 200; i++)
        for (j = 1; j < 200; j++)
      {
        if (now[i][j] && (now[i - 1][j] || now[i][j - 1]))
          next[i][j] = 1, n++;

        if ((!now[i][j]) && (now[i - 1][j] && now[i][j - 1]))
          next[i][j] = 1, n++;

      }


      for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
        now[i][j] = next[i][j];


    }

    printf("Case #%d: %d\n", ++count, res);
  }

  return 0;
}


