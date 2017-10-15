#include <stdio.h>
enum {MAXN = 64};
int n;
int row[MAXN];
void input(void)
{
  int first_iteration;
  int dis;
  int tc;
  static char curr_row[MAXN];
  scanf("%d\n", &n);
  for (dis = 0; dis < n; dis++)
  {
    gets(curr_row);
    row[dis] = 0;
    for (tc = 0; curr_row[tc]; tc++)
    {
      if (curr_row[tc] == '1')
      {
        row[dis] = tc;
      }

    }

  }

}

int calc(void)
{
  int first_iteration;
  int dis;
  int tc;
  int price;
  int temp;
  static int pos[MAXN];
  for (dis = 0; dis < n; dis++)
  {
    for (tc = 0; tc < n; tc++)
    {
      if (row[tc] <= dis)
      {
        pos[tc] = dis;
        row[tc] = MAXN;
        break;
      }

    }

  }

  price = 0;
  for (dis = 0; dis < n; dis++)
  {
    for (tc = 0; tc < n; tc++)
    {
      if (pos[tc] == dis)
      {
        break;
      }

    }

    for (; tc > dis; tc--)
    {
      temp = pos[tc];
      pos[tc] = pos[tc - 1];
      pos[tc - 1] = temp;
      price++;
    }

  }

  return price;
}

int Main(void)
{
  int first_iteration;
  int bin;
  int test;
  scanf("%d\n", &bin);
  for (test = 1; test <= bin; test++)
  {
    input();
    printf("Case #%d: %d\n", test, calc());
  }

  return 0;
}


