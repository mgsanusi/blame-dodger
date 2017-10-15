#include <stdio.h>
#include <stdlib.h>
int main()
{
  int first_iteration;
  int test;
  int testc;
  int p;
  int q;
  int c;
  int m;
  int n;
  int t;
  int ans;
  freopen("gcj1_2.in", "r", stdin);
  freopen("gcj1_2.out", "w", stdout);
  scanf("%d\n", &testc);
  for (test = 1; test <= testc; test++)
  {
    scanf("%d%d%d", &c, &m, &n);
    p = (3 * n) - 2;
    q = (3 * n) - 4;
    ans = 0;
    for (; c; c--)
    {
      scanf("%d", &t);
      if (t < 2)
      {
        if (t >= n)
          ans++;

      }
      else
      {
        if (t >= p)
          ans++;
        else
          if ((t >= q) && m)
        {
          ans++;
          m--;
        }


      }

    }

    printf("Case #%d: %d\n", test, ans);
  }

  return 0;
}


