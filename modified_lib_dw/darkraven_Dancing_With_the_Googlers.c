#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  scanf("%d", &t);
  int i;
  for (i = 1; i <= t; i++)
  {
    printf("Case #%d: ", i);
    int c1 = 0;
    int c2 = 0;
    int s;
    int p;
    int k;
    scanf("%d%d%d", &k, &s, &p);
    int j;
    for (j = 0; j < k; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      if (((tmp / 3) >= p) || ((((tmp / 3) + 1) >= p) && ((tmp % 3) != 0)))
      {
        c1++;
      }
      else
        if (((((tmp % 3) == 0) && (((tmp / 3) + 1) >= p)) && tmp) || (((tmp % 3) == 2) && (((tmp / 3) + 2) >= p)))
      {
        c2++;
      }


    }

    int ans = c1 + (s < c2 ? s : c2);
    printf("%d\n", ans);
  }

  return 0;
}


