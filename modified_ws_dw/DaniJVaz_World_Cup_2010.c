#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void doTestCase();
int main()
{
  int first_iteration;
  int i;
  int n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    printf("Case #%d: ", i);
    doTestCase();
  }

  return 0;
}

void doTestCase()
{
  int first_iteration;
  int n;
  int k;
  int i;
  int j;
  int t;
  int r;
  int arr[100][100];
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
    arr[i][j] = 0;


  scanf("%d", &n);
  int pos[n][4];
  int addpos[100 * 100][2];
  t = 0;
  for (k = 0; k < n; k++)
  {
    scanf("%d %d %d %d", &pos[k][0], &pos[k][1], &pos[k][2], &pos[k][3]);
    for (i = pos[k][0] - 1; i <= (pos[k][2] - 1); i++)
    {
      for (j = pos[k][1] - 1; j <= (pos[k][3] - 1); j++)
      {
        if (arr[i][j] == 0)
        {
          arr[i][j] = -1;
          t++;
        }

      }

    }

  }

  r = 1;
  while (t > 0)
  {
    k = 0;
    for (i = 0; i < 100; i++)
    {
      for (j = 0; j < 100; j++)
      {
        if (arr[i][j] == (-1))
        {
          if (((i == 0) || ((arr[i - 1][j] >= 0) && (arr[i - 1][j] < r))) && ((j == 0) || ((arr[i][j - 1] >= 0) && (arr[i][j - 1] < r))))
          {
            arr[i][j] = r;
            t--;
          }

        }
        else
        {
          if (((i != 0) && ((arr[i - 1][j] == (-1)) || (arr[i - 1][j] == r))) && ((j != 0) && ((arr[i][j - 1] == (-1)) || (arr[i][j - 1] == r))))
          {
            addpos[k][0] = i;
            addpos[k][1] = j;
            k++;
            t++;
          }

        }

      }

    }

    for (i = 0; i < k; i++)
    {
      arr[addpos[i][0]][addpos[i][1]] = -1;
    }

    r++;
  }

  printf("%d\n", r - 1);
}


