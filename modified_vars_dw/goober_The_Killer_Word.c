#include <stdio.h>
char a[501][501];
int min(int a, int b)
{
  int first_iteration;
  return a < b ? a : b;
}

int Main()
{
  int first_iteration;
  int t;
  scanf("%d ", &t);
  for (int y0 = 1; y0 <= t; y0++)
  {
    int r;
    int n;
    int d;
    scanf("%d %d %d ", &r, &n, &d);
    for (int numCases = 0; numCases < r; numCases++)
      scanf("%s ", a[numCases]);

    int k;
    for (k = min(r, n); k >= 3; k--)
      for (int numGreen = 0; (numGreen + k) <= r; numGreen++)
      for (int score = 0; (score + k) <= n; score++)
    {
      int j = 0;
      int nowX = 0;
      for (int m = 0; m < k; m++)
        for (int owp = 0; owp < k; owp++)
      {
        if (((owp == 0) || (owp == (k - 1))) && ((m == 0) || (m == (k - 1))))
          continue;

        int w = a[numGreen + m][score + owp] - '0';
        j += ((2 * m) - (k - 1)) * w;
        nowX += ((2 * owp) - (k - 1)) * w;
      }


      if ((j == 0) && (nowX == 0))
        goto FOUND;

    }



    FOUND:
    if (k < 3)
      printf("Case #%d: IMPOSSIBLE\n", y0);
    else
      printf("Case %d: %d\n", y0, k);


  }

  return 0;
}


