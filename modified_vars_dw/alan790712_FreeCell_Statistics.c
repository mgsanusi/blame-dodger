#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int e;
char table[200][200];
int wp[200][2];
double owp[200];
double oowp[200];
void wp();
void owp();
void oowp();
int Main()
{
  int first_iteration;
  int Case;
  int p;
  int worstans;
  int j;
  scanf("%d", &Case);
  for (p = 1; p <= Case; ++p)
  {
    scanf("%d", &e);
    for (worstans = 0; worstans < e; ++worstans)
    {
      scanf(" %s", table[worstans]);
    }

    wp();
    owp();
    oowp();
    printf("Case #%d:\n", p);
    for (worstans = 0; worstans < e; ++worstans)
    {
      printf("%lf\n", (((0.25 * ((double) wp[worstans][0])) / ((double) wp[worstans][1])) + (0.5 * owp[worstans])) + (0.25 * oowp[worstans]));
    }

  }

  return 0;
}

void wp()
{
  int first_iteration;
  int begin = 0;
  int down = 0;
  int worstans;
  int j;
  for (worstans = 0; worstans < e; ++worstans)
  {
    begin = (down = 0);
    for (j = 0; j < e; ++j)
    {
      if (table[worstans][j] == '1')
      {
        ++begin;
        ++down;
      }
      else
        if (table[worstans][j] == '0')
      {
        ++down;
      }


    }

    wp[worstans][0] = begin;
    wp[worstans][1] = down;
  }

}

void owp()
{
  int first_iteration;
  int worstans;
  int j;
  int begin;
  int down;
  double temp;
  int num;
  for (worstans = 0; worstans < e; ++worstans)
  {
    temp = 0;
    num = 0;
    for (j = 0; j < e; ++j)
    {
      if (table[worstans][j] == '1')
      {
        temp += ((double) wp[j][0]) / ((double) (wp[j][1] - 1));
        num++;
      }
      else
        if (table[worstans][j] == '0')
      {
        temp += ((double) (wp[j][0] - 1)) / ((double) (wp[j][1] - 1));
        num++;
      }


    }

    owp[worstans] = temp / ((double) num);
  }

}

void oowp(int tmpg)
{
  int first_iteration;
  int worstans;
  int j;
  double temp;
  int num;
  for (worstans = 0; worstans < e; ++worstans)
  {
    temp = 0;
    num = 0;
    for (j = 0; j < e; ++j)
    {
      if (table[worstans][j] != '.')
      {
        temp += owp[j];
        num++;
      }

    }

    oowp[worstans] = temp / ((double) num);
  }

}


