#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void do_test_case();
int Main()
{
  int dp;
  int p;
  scanf("%d", &p);
  for (dp = 1; dp <= p; dp++)
  {
    printf("Case #%d: ", dp);
    do_test_case();
  }

  return 0;
}

void do_test_case()
{
  int p;
  int k;
  int dp;
  int len;
  int m;
  int rightptr;
  int array[100][100];
  for (dp = 0; dp < 100; dp++)
    for (len = 0; len < 100; len++)
    array[dp][len] = 0;


  scanf("%d", &p);
  int pos[p][4];
  int addpos[100 * 100][2];
  m = 0;
  for (k = 0; k < p; k++)
  {
    scanf("%d %d %d %d", &pos[k][0], &pos[k][1], &pos[k][2], &pos[k][3]);
    for (dp = pos[k][0] - 1; dp <= (pos[k][2] - 1); dp++)
    {
      for (len = pos[k][1] - 1; len <= (pos[k][3] - 1); len++)
      {
        if (array[dp][len] == 0)
        {
          array[dp][len] = -1;
          m++;
        }

      }

    }

  }

  rightptr = 1;
  while (m > 0)
  {
    k = 0;
    for (dp = 0; dp < 100; dp++)
    {
      for (len = 0; len < 100; len++)
      {
        if (array[dp][len] == (-1))
        {
          if (((dp == 0) || ((array[dp - 1][len] >= 0) && (array[dp - 1][len] < rightptr))) && ((len == 0) || ((array[dp][len - 1] >= 0) && (array[dp][len - 1] < rightptr))))
          {
            array[dp][len] = rightptr;
            m--;
          }

        }
        else
        {
          if (((dp != 0) && ((array[dp - 1][len] == (-1)) || (array[dp - 1][len] == rightptr))) && ((len != 0) && ((array[dp][len - 1] == (-1)) || (array[dp][len - 1] == rightptr))))
          {
            addpos[k][0] = dp;
            addpos[k][1] = len;
            k++;
            m++;
          }

        }

      }

    }

    for (dp = 0; dp < k; dp++)
    {
      array[addpos[dp][0]][addpos[dp][1]] = -1;
    }

    rightptr++;
  }

  printf("%d\n", rightptr - 1);
}


