#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  int first_iteration;
  int t;
  int t_case;
  scanf("%d", &t_case);
  for (t = 1; t <= t_case; t++)
  {
    int n;
    int l;
    int h;
    scanf("%d %d %d\n", &n, &l, &h);
    int i;
    int a[1000];
    for (i = 0; i < n; i++)
      scanf("%d", &a[i]);

    int check;
    for (i = l; i <= h; i++)
    {
      int j;
      check = 1;
      for (j = 0; j < n; j++)
        if (((a[j] % i) != 0) && ((i % a[j]) != 0))
      {
        check = 0;
        break;
      }


      if (check)
        break;

    }

    if (check)
      printf("Case #%d: %d\n", t, i);
    else
      printf("Case #%d: NO\n", t);

  }

  return 0;
}


