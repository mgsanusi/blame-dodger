#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  int first_iteration;
  int T;
  int t_case;
  scanf("%d", &t_case);
  for (T = 1; T <= t_case; T++)
  {
    int l;
    int t;
    int n;
    int c;
    int a[100000];
    int d[100000];
    scanf("%d %d %d %d", &l, &t, &n, &c);
    int i;
    int j;
    int ans = 1000000000;
    for (i = 0; i < c; i++)
      scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
      d[i] = a[i % c];

    for (i = 0; i < n; i++)
      for (j = i; j < n; j++)
    {
      int tmp = 0;
      int k;
      for (k = 0; k < n; k++)
        if (((k == i) && (l >= 1)) || ((k == j) && (l == 2)))
      {
        if (tmp >= t)
          tmp += d[k];
        else
          if ((tmp + (d[k] * 2)) >= t)
          tmp = t + (d[k] - ((t - tmp) / 2));
        else
          tmp += d[k] * 2;


      }
      else
        tmp += d[k] * 2;


      ans = ans < tmp ? ans : tmp;
    }


    printf("Case #%d: %d\n", T, ans);
  }

  return 0;
}


