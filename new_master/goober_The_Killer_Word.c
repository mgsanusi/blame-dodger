#include <stdio.h>

char a[501][501];

int min(int a, int b) { return a<b?a:b; }

int main()
{
  int T;
  scanf("%d ", &T);
  for (int t=1; t<=T; t++)
  {
    int r, c, d;
    scanf("%d %d %d ", &r, &c, &d);
    for (int i=0; i<r; i++)
      scanf("%s ", a[i]);
    int k;
    for (k = min(r,c); k >= 3; k--)
      for (int rs = 0; rs + k <= r; rs++)
        for (int cs = 0; cs + k <= c; cs++)
        {
          int tr = 0, tc = 0;
          for (int rr = 0; rr < k; rr++)
            for (int cc =0; cc < k; cc++)
            {
              if ((cc == 0 || cc == k-1) && (rr == 0 || rr == k-1))
                continue;
              int w = a[rs+rr][cs+cc] - '0';
              tr += (2*rr-(k-1)) * w;
              tc += (2*cc-(k-1)) * w;
            }
          if (tr == 0 && tc == 0)
            goto FOUND;
        }
FOUND:
    if (k < 3)
      printf("Case #%d: IMPOSSIBLE\n", t);
    else
      printf("Case %d: %d\n", t, k);
  }
  return 0;
}
