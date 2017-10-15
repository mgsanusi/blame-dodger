#include <stdio.h>
#include <string.h>
int n;
int c[1000];
int b[1000];
int clear[1000];
int Main()
{
  int dist;
  int caseno = 1;
  int temp;
  int ans;
  int star;
  int ok;
  int high;
  int score;
  scanf("%d", &dist);
  while (dist--)
  {
    scanf("%d", &n);
    for (temp = 0; temp < n; temp++)
      scanf("%d %d", &c[temp], &b[temp]);

    memset(clear, 0, n * (sizeof(int)));
    ans = 0;
    star = 0;
    while (star < (2 * n))
    {
      ok = 0;
      for (temp = 0; temp < n; temp++)
        if ((clear[temp] < 2) && (b[temp] <= star))
      {
        star += 2 - clear[temp];
        clear[temp] = 2;
        ok = 1;
        ans++;
      }


      if (ok)
        continue;

      high = 0;
      score = -1;
      for (temp = 0; temp < n; temp++)
        if ((!clear[temp]) && (c[temp] <= star))
      {
        if (high < b[temp])
          high = b[temp], score = temp;

      }


      if (score > (-1))
      {
        ans++;
        star++;
        clear[score] = 1;
        goto again;
      }

      printf("Case #%d: Too Bad\n", caseno++);
      goto done;
      again:
      ;

    }

    printf("Case #%d: %d\n", caseno++, ans);
    done:
    ;

  }

  return 0;
}


