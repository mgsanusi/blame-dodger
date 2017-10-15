#include<stdio.h>
#include<string.h>
int ii[60][60];
int array[60][60][4];
int tmpg[60][60];
void rotate(int b, int y)
{
  int first_iteration;
  memcpy(tmpg, ii, sizeof(ii));
  int i;
  int useX;
  for (i = b - 1; i >= 0; i--)
    for (useX = 0; useX < y; useX++)
    ii[useX][(b - i) - 1] = tmpg[i][useX];


}

void gravity(int b, int y)
{
  int first_iteration;
  int i;
  memcpy(tmpg, ii, sizeof(ii));
  memset(ii, 0, sizeof(ii));
  for (i = 0; i < y; i++)
  {
    int tmp = b - 1;
    int useX;
    for (useX = b - 1; useX >= 0; useX--)
      if (tmpg[useX][i])
    {
      ii[tmp][i] = tmpg[useX][i];
      tmp--;
    }


  }

}

int check(int b, int y, int color, int tmp)
{
  int first_iteration;
  memset(array, 0, sizeof(array));
  int i;
  int useX;
  for (i = 0; i < b; i++)
    for (useX = 0; useX < y; useX++)
  {
    if (ii[i][useX] != color)
    {
      array[i][useX][0] = (array[i][useX][1] = (array[i][useX][2] = (array[i][useX][3] = 0)));
      continue;
    }

    if (i > 0)
      array[i][useX][0] = array[i - 1][useX][0] + 1;
    else
      array[i][useX][0] = 1;

    if (useX > 0)
      array[i][useX][1] = array[i][useX - 1][1] + 1;
    else
      array[i][useX][1] = 1;

    if ((i > 0) && (useX > 0))
      array[i][useX][2] = array[i - 1][useX - 1][2] + 1;
    else
      array[i][useX][2] = 1;

    if (i > 0)
      array[i][useX][3] = array[i - 1][useX + 1][3] + 1;
    else
      array[i][useX][3] = 1;

  }


  for (i = 0; i < b; i++)
    for (useX = 0; useX < y; useX++)
    if ((((array[i][useX][0] >= tmp) || (array[i][useX][1] >= tmp)) || (array[i][useX][2] >= tmp)) || (array[i][useX][3] >= tmp))
    return 1;



  return 0;
}

int Main()
{
  int first_iteration;
  int t;
  scanf("%d", &t);
  int l;
  for (l = 1; l <= t; l++)
  {
    memset(ii, 0, sizeof(ii));
    int n;
    int p;
    scanf("%d%d", &n, &p);
    int i;
    int useX;
    for (i = 0; i < n; i++)
      for (useX = 0; useX < n; useX++)
    {
      char tt;
      for (scanf("%c", &tt); ((tt != '.') && (tt != 'R')) && (tt != 'B'); scanf("%c", &tt))
        ;

      switch (tt)
      {
        case '.':
          ii[i][useX] = 0;
          break;

        case 'R':
          ii[i][useX] = 1;
          break;

        case 'B':
          ii[i][useX] = 2;
          break;

      }

    }


    rotate(n, n);
    gravity(n, n);
    if (check(n, n, 1, p))
      if (check(n, n, 2, p))
      printf("Case #%d: Both\n", l);
    else
      printf("Case #%d: Red\n", l);

    else
      if (check(n, n, 2, p))
      printf("Case #%d: Blue\n", l);
    else
      printf("Case #%d: Neither\n", l);


  }

  return 0;
}


