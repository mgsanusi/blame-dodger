#include <stdio.h>
#include <assert.h>
#include <string.h>
int n;
long double f(int n)
{
  return n - ((n - 1) * 0.5);
}

long double x[205 * 2];
long double sum[205 * 2][205 * 2];
long double b[205 * 2][205 * 2];
int num[205 * 2][205 * 2];
long double q[205 * 2][205 * 2];
char s[205];
void clear(void)
{
  scanf("%s\n", s);
  assert(strlen(s) <= 200);
  memset(x, 0, sizeof(x));
  memset(sum, 0, sizeof(sum));
  memset(b, 0, sizeof(b));
  memset(num, 0, sizeof(num));
  memset(q, 0, sizeof(q));
  int n = strlen(s);
  n = n;
  int m;
  int num;
  int cntj = 0;
  for (m = 0; m < n; m++)
  {
    x[m] = s[m] == 'X';
    x[m + n] = x[m];
    cntj += 1 - x[m];
  }

  for (m = 0; m <= (2 * n); m++)
  {
    sum[m][m] = 1;
    num[m][m] = 1 - x[m];
  }

  for (m = 0; m < (2 * n); m++)
    for (num = m + 1; num < (2 * n); num++)
    num[m][num] = num[m][num - 1] + (1 - x[num]);


  b[0][0] = 1;
  for (m = 1; m <= n; m++)
  {
    b[m][0] = 1;
    for (num = 1; num <= m; num++)
      b[m][num] = b[m - 1][num] + b[m - 1][num - 1];

  }

  int l;
  for (l = 2; l <= n; l++)
  {
    for (m = 0; (m < (2 * n)) && ((m + l) <= (2 * n)); m++)
    {
      int x2;
      long double dy = 0;
      int ok = 0;
      num = (m + l) - 1;
      for (x2 = m; x2 < (m + l); x2++)
        if (!x[x2])
      {
        ok = 1;
        dy += (((x2 >= (m + 1) ? sum[m][x2 - 1] : 1) * (x2 <= (num - 1) ? sum[x2 + 1][num] : 1)) * ((x2 - m) + 1)) * b[(x2 >= (m + 1) ? num[m][x2 - 1] : 0) + (x2 <= (num - 1) ? num[x2 + 1][num] : 0)][x2 >= (m + 1) ? num[m][x2 - 1] : 0];
        assert(((((x2 >= (m + 1) ? sum[m][x2 - 1] : 1) * (x2 <= (num - 1) ? sum[x2 + 1][num] : 1)) * ((x2 - m) + 1)) * b[(x2 >= (m + 1) ? num[m][x2 - 1] : 0) + (x2 <= (num - 1) ? num[x2 + 1][num] : 0)][x2 >= (m + 1) ? num[m][x2 - 1] : 0]) >= 0);
      }


      if (!ok)
      {
        dy = 1;
      }

      assert(dy > 0);
      sum[m][num] = dy;
    }

  }

  for (l = 1; l <= n; l++)
  {
    for (m = 0; (m < (2 * n)) && ((m + l) <= (2 * n)); m++)
    {
      int num = (m + l) - 1;
      int x2;
      long double dy = 0;
      for (x2 = m; x2 <= num; x2++)
        if (!x[x2])
      {
        dy += (((((x2 >= (m + 1) ? sum[m][x2 - 1] : 1) * (x2 <= (num - 1) ? sum[x2 + 1][num] : 1)) * ((x2 - m) + 1)) * b[(x2 >= (m + 1) ? num[m][x2 - 1] : 0) + (x2 <= (num - 1) ? num[x2 + 1][num] : 0)][x2 >= (m + 1) ? num[m][x2 - 1] : 0]) / sum[m][num]) * (((x2 >= (m + 1) ? q[m][x2 - 1] : 0) + (x2 <= (num - 1) ? q[x2 + 1][num] : 0)) + f((x2 - m) + 1));
      }


      q[m][num] = dy;
    }

  }

  long double elements = 0;
  for (m = 0; m < n; m++)
    if (!x[(m + n) - 1])
  {
    num = (m + n) - 1;
    int x2 = num;
    assert(((((x2 >= (m + 1) ? sum[m][x2 - 1] : 1) * (x2 <= (num - 1) ? sum[x2 + 1][num] : 1)) * ((x2 - m) + 1)) * b[(x2 >= (m + 1) ? num[m][x2 - 1] : 0) + (x2 <= (num - 1) ? num[x2 + 1][num] : 0)][x2 >= (m + 1) ? num[m][x2 - 1] : 0]) <= sum[m][num]);
    int cases;
    long double eee = ((((x2 >= (m + 1) ? sum[m][x2 - 1] : 1) * (x2 <= (num - 1) ? sum[x2 + 1][num] : 1)) * ((x2 - m) + 1)) * b[(x2 >= (m + 1) ? num[m][x2 - 1] : 0) + (x2 <= (num - 1) ? num[x2 + 1][num] : 0)][x2 >= (m + 1) ? num[m][x2 - 1] : 0]) * ((num >= (m + 1) ? q[m][num - 1] : 0) + f(n));
    for (cases = 0; cases < cntj; cases++)
    {
      eee /= n;
    }

    elements += eee;
  }


  printf("%18.18lf\n", (double) elements);
}

int Main()
{
  int caso;
  assert(scanf("%d\n", &caso) > 0);
  int __;
  for (__ = 0; __ < caso; __++)
  {
    printf("Case #%d: ", __ + 1);
    clear();
  }

  return 0;
}


