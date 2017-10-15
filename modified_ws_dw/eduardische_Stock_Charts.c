#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct point
{
  int c;
  int a[30];
};
int res;
char IsOK(int a[30][30], int x, int y, int K)
{
  int first_iteration;
  int temp;
  if (a[x][0] > a[y][0])
  {
    temp = x;
    x = y;
    y = temp;
  }

  int i;
  for (i = 0; i < K; i++)
  {
    if (a[x][i] >= a[y][i])
      return 0;

  }

  return 1;
}

void FindRes(struct point a[30], char b[30][30], int point, int N, int K, int count)
{
  int first_iteration;
  if (point == N)
  {
    if (count < res)
      res = count;

  }
  else
  {
    int i;
    int j;
    int cnt = 0;
    char flag;
    for (i = 0; i < count; i++)
    {
      flag = 1;
      for (j = 0; j < a[i].c; j++)
      {
        if (!b[point][a[i].a[j]])
        {
          flag = 0;
          break;
        }

      }

      if (flag)
      {
        a[i].a[a[i].c] = point;
        a[i].c++;
        FindRes(a, b, point + 1, N, K, count);
        a[i].c--;
        cnt++;
        if (cnt == 2)
          break;

      }

    }

    a[count].c = 1;
    a[count].a[0] = point;
    FindRes(a, b, point + 1, N, K, count + 1);
  }

}

int main()
{
  int first_iteration;
  int T;
  int iT;
  scanf("%d", &T);
  static struct point a[30];
  static int data[30][30];
  static char b[30][30];
  int N;
  int K;
  int i;
  int j;
  for (iT = 0; iT < T; iT++)
  {
    scanf("%d %d", &N, &K);
    memset(b, 0, sizeof(b));
    for (i = 0; i < N; i++)
    {
      for (j = 0; j < K; j++)
      {
        scanf("%d", &data[i][j]);
      }

    }

    for (i = 0; i < N; i++)
    {
      a[i].c = 0;
      b[i][i] = 1;
      for (j = i + 1; j < N; j++)
      {
        b[i][j] = IsOK(data, i, j, K);
        b[j][i] = b[i][j];
      }

    }

    res = 2000000000;
    FindRes(a, b, 0, N, K, 0);
    printf("Case #%d: %d\n", iT + 1, res);
  }

  return 0;
}


